#ifndef VARIABLEDIRECTIVE_H
#define VARIABLEDIRECTIVE_H

#include <QDate>

#include "directive.h"

/*
 * =============================================================================
 * V  A  R  I  A  B  L  E  D  I  R  E  C  T  I  V  E     C  L  A  S  S
 * =============================================================================
 *
 * Summary:
 *     Like base class Directive, represents a command from the application to
 *     the user to perform or not to perform certain actions. For this class,
 *     the Threshold varies based on the current date and supplied start and
 *     end dates.
 *
 * =============================================================================
 */

class VariableDirective : public Directive
{
    Q_GADGET
public:
    // -------------------------------------------------------------------------
    // [VariableDirective]   L I F E - C Y C L E
    // -------------------------------------------------------------------------
    // Defaulted constructor, copy constructor, and destructor
    VariableDirective() = default;
    VariableDirective(const VariableDirective& directive) = default;
    ~VariableDirective() = default;

    // Usable constructor
    VariableDirective(const QString& name,
                      const QString& description,
                      const Valence& valence,
                      const QDate& startDate,
                      const QDate& endDate,
                      const double& startThreshold,
                      const double& endThreshold);

    // Copy assignment operator
    VariableDirective& operator=(const VariableDirective& directive) = default;

    // -------------------------------------------------------------------------
    // [Directive]   M E M B E R S
    // -------------------------------------------------------------------------
    double threshold() const override;

    // -------------------------------------------------------------------------
    // [VariableDirective]   M E M B E R S
    // -------------------------------------------------------------------------
    // Accessors
    QDate startDate() const {return m_startDate;}
    QDate endDate() const {return m_endDate;}
    double startThreshold() const {return m_startThreshold;}
    double endThreshold() const {return m_endThreshold;}

    // Mutators
    void setStartDate(const QDate& d);
    void setEndDate(const QDate& d);
    void setStartThreshold(const double& t);
    void setEndThreshold(const double& t);

protected:
    // -------------------------------------------------------------------------
    // [Directive]   S T O R E D   Q V A R I A N T   H E L P E R S
    // -------------------------------------------------------------------------
    QVariantMap writeSelfToMap() const override;
    void readMapToSelf(const QVariantMap& map) override;
    QMetaObject getStaticMetaObject() const override;

private:
    // -------------------------------------------------------------------------
    // [VariableDirective]   D A T A   M E M B E R S
    // -------------------------------------------------------------------------
    QDate m_startDate = QDate::currentDate();
    QDate m_endDate = QDate::currentDate().addMonths(2);
    double m_startThreshold = 0.7;
    double m_endThreshold = 0.3;
};
Q_DECLARE_METATYPE(VariableDirective)

#endif // VARIABLEDIRECTIVE_H
