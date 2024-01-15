#include "dayfocus.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QListView>
#include <QPushButton>
#include <QVBoxLayout>

#include "../session/profile.h"

#include <iostream>
using std::cout, std::endl;

DayFocus::DayFocus(QSharedPointer<Profile> profile, QWidget *parent)
    : QWidget{parent}
    , m_activeDate(QDate::currentDate())
    , m_activeProfile(profile)
{
    // // DEBUG
    // {
    //     cout << "----------------------------------------" << endl;
    //     cout << "\tBP00" << endl;
    //     cout << "\t- Constructor entered" << endl;
    //     cout << "----------------------------------------" << endl;
    //     cout << "--------------------" << endl;
    //     cout << "For this:" << endl;
    //     cout << "--------------------" << endl;
    //     cout << "Size:" << endl;
    //     cout << "\tHeight: " << this->size().height() << endl;
    //     cout << "\tWidth: " << this->size().width() << endl << endl;
    // }
    // // DEBUG
    auto layout = new QVBoxLayout();
    setLayout(layout);
    auto margin = QMargins(8, 8, 8, 8);
    layout->setContentsMargins(margin);
    // // DEBUG
    // {
    //     cout << "----------------------------------------" << endl;
    //     cout << "\tBP01" << endl;
    //     cout << "\t- Layout with margins created" << endl;
    //     cout << "\t  and added to this." << endl;
    //     cout << "----------------------------------------" << endl;
    //     cout << "--------------------" << endl;
    //     cout << "For this:" << endl;
    //     cout << "--------------------" << endl;
    //     cout << "Size:" << endl;
    //     cout << "\tHeight: " << this->size().height() << endl;
    //     cout << "\tWidth: " << this->size().width() << endl << endl;
    //     cout << "--------------------" << endl;
    //     cout << "For layout:" << endl;
    //     cout << "--------------------" << endl;
    //     cout << "Size Hint:" << endl;
    //     cout << "\tHeight: " << layout->sizeHint().height() << endl;
    //     cout << "\tWidth: " << layout->sizeHint().width() << endl << endl;
    //     cout << "Minimum Size:" << endl;
    //     cout << "\tHeight: " << layout->minimumSize().height() << endl;
    //     cout << "\tWidth: " << layout->minimumSize().width() << endl << endl;
    //     cout << "Maximum Size:" << endl;
    //     cout << "\tHeight: " << layout->maximumSize().height() << endl;
    //     cout << "\tWidth: " << layout->maximumSize().width() << endl << endl;
    // }
    // // DEBUG


    auto title = new QLabel(this);
    layout->addWidget(title);
    title->setFrameStyle(QFrame::Panel | QFrame::Raised);
    title->setText("DayRoller - Daily Directives:");
    title->setFont(QFont("Helvetica", 20, 8));
    title->setAlignment(Qt::AlignCenter);
    title->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    // // DEBUG
    // {
    //     cout << "----------------------------------------" << endl;
    //     cout << "\tBP02" << endl;
    //     cout << "\t- Title created and added to" << endl;
    //     cout << "\t  layout" << endl;
    //     cout << "----------------------------------------" << endl;
    //     cout << "--------------------" << endl;
    //     cout << "For this:" << endl;
    //     cout << "--------------------" << endl;
    //     cout << "Size:" << endl;
    //     cout << "\tHeight: " << this->size().height() << endl;
    //     cout << "\tWidth: " << this->size().width() << endl << endl;
    //     cout << "--------------------" << endl;
    //     cout << "For layout:" << endl;
    //     cout << "--------------------" << endl;
    //     cout << "Size Hint:" << endl;
    //     cout << "\tHeight: " << layout->sizeHint().height() << endl;
    //     cout << "\tWidth: " << layout->sizeHint().width() << endl << endl;
    //     cout << "Minimum Size:" << endl;
    //     cout << "\tHeight: " << layout->minimumSize().height() << endl;
    //     cout << "\tWidth: " << layout->minimumSize().width() << endl << endl;
    //     cout << "Maximum Size:" << endl;
    //     cout << "\tHeight: " << layout->maximumSize().height() << endl;
    //     cout << "\tWidth: " << layout->maximumSize().width() << endl << endl;
    //     cout << "--------------------" << endl;
    //     cout << "For title:" << endl;
    //     cout << "--------------------" << endl;
    //     cout << "Size Hint:" << endl;
    //     cout << "\tHeight: " << title->sizeHint().height() << endl;
    //     cout << "\tWidth: " << title->sizeHint().width() << endl << endl;
    //     cout << "Minimum Size:" << endl;
    //     cout << "\tHeight: " << title->minimumSize().height() << endl;
    //     cout << "\tWidth: " << title->minimumSize().width() << endl << endl;
    //     cout << "Maximum Size:" << endl;
    //     cout << "\tHeight: " << title->maximumSize().height() << endl;
    //     cout << "\tWidth: " << title->maximumSize().width() << endl << endl;
    // }
    // // DEBUG


    layout->addSpacing(8);


    auto navLayout = new QHBoxLayout();
    layout->addLayout(navLayout);
    // // DEBUG
    // {
    //     cout << "----------------------------------------" << endl;
    //     cout << "\tBP05" << endl;
    //     cout << "\t- Layout navLayout created" << endl;
    //     cout << "\t  and added to layout" << endl;
    //     cout << "----------------------------------------" << endl;
    //     cout << "--------------------" << endl;
    //     cout << "For this:" << endl;
    //     cout << "--------------------" << endl;
    //     cout << "Size:" << endl;
    //     cout << "\tHeight: " << this->size().height() << endl;
    //     cout << "\tWidth: " << this->size().width() << endl << endl;
    //     cout << "--------------------" << endl;
    //     cout << "For layout:" << endl;
    //     cout << "--------------------" << endl;
    //     cout << "Size Hint:" << endl;
    //     cout << "\tHeight: " << layout->sizeHint().height() << endl;
    //     cout << "\tWidth: " << layout->sizeHint().width() << endl << endl;
    //     cout << "Minimum Size:" << endl;
    //     cout << "\tHeight: " << layout->minimumSize().height() << endl;
    //     cout << "\tWidth: " << layout->minimumSize().width() << endl << endl;
    //     cout << "Maximum Size:" << endl;
    //     cout << "\tHeight: " << layout->maximumSize().height() << endl;
    //     cout << "\tWidth: " << layout->maximumSize().width() << endl << endl;
    //     cout << "--------------------" << endl;
    //     cout << "For navLayout:" << endl;
    //     cout << "--------------------" << endl;
    //     cout << "Size Hint:" << endl;
    //     cout << "\tHeight: " << navLayout->sizeHint().height() << endl;
    //     cout << "\tWidth: " << navLayout->sizeHint().width() << endl << endl;
    //     cout << "Minimum Size:" << endl;
    //     cout << "\tHeight: " << navLayout->minimumSize().height() << endl;
    //     cout << "\tWidth: " << navLayout->minimumSize().width() << endl << endl;
    //     cout << "Maximum Size:" << endl;
    //     cout << "\tHeight: " << navLayout->maximumSize().height() << endl;
    //     cout << "\tWidth: " << navLayout->maximumSize().width() << endl << endl;
    // }
    // // DEBUG


    auto leftButton = new QPushButton(this);
    navLayout->addWidget(leftButton, 0, Qt::AlignLeft);
    leftButton->setIcon(QIcon(":/icons/dateNavButtonLeft.png"));
    leftButton->setIconSize(QSize(36,36));
    QObject::connect(leftButton, &QPushButton::clicked, this,
                     [this]() {
                         setActiveDate(m_activeDate.addDays(-1));
    });
    leftButton->setToolTip("Go to previous day.");
    // // DEBUG
    // {
    //     cout << "----------------------------------------" << endl;
    //     cout << "\tBP06" << endl;
    //     cout << "\t- Left button added to" << endl;
    //     cout << "\t  navLayout" << endl;
    //     cout << "----------------------------------------" << endl;
    //     cout << "--------------------" << endl;
    //     cout << "For this:" << endl;
    //     cout << "--------------------" << endl;
    //     cout << "Size:" << endl;
    //     cout << "\tHeight: " << this->size().height() << endl;
    //     cout << "\tWidth: " << this->size().width() << endl << endl;
    //     cout << "--------------------" << endl;
    //     cout << "For layout:" << endl;
    //     cout << "--------------------" << endl;
    //     cout << "Size Hint:" << endl;
    //     cout << "\tHeight: " << layout->sizeHint().height() << endl;
    //     cout << "\tWidth: " << layout->sizeHint().width() << endl << endl;
    //     cout << "Minimum Size:" << endl;
    //     cout << "\tHeight: " << layout->minimumSize().height() << endl;
    //     cout << "\tWidth: " << layout->minimumSize().width() << endl << endl;
    //     cout << "Maximum Size:" << endl;
    //     cout << "\tHeight: " << layout->maximumSize().height() << endl;
    //     cout << "\tWidth: " << layout->maximumSize().width() << endl << endl;
    //     cout << "--------------------" << endl;
    //     cout << "For navLayout:" << endl;
    //     cout << "--------------------" << endl;
    //     cout << "Size Hint:" << endl;
    //     cout << "\tHeight: " << navLayout->sizeHint().height() << endl;
    //     cout << "\tWidth: " << navLayout->sizeHint().width() << endl << endl;
    //     cout << "Minimum Size:" << endl;
    //     cout << "\tHeight: " << navLayout->minimumSize().height() << endl;
    //     cout << "\tWidth: " << navLayout->minimumSize().width() << endl << endl;
    //     cout << "Maximum Size:" << endl;
    //     cout << "\tHeight: " << navLayout->maximumSize().height() << endl;
    //     cout << "\tWidth: " << navLayout->maximumSize().width() << endl << endl;
    // }
    // // DEBUG

    auto dateDisp = new QLabel(this);
    navLayout->addWidget(dateDisp, 0, Qt::AlignCenter);
    dateDisp->setText(m_activeDate.toString(Qt::TextDate));
    dateDisp->setFont(QFont("Helvetica", 14, 1));
    QObject::connect(this, &DayFocus::activeDateChanged, this,
                     [dateDisp](const QDate& newActiveDate) {
                         dateDisp->setText(newActiveDate.toString(Qt::TextDate));
                     });
    // // DEBUG
    // {
    //     cout << "----------------------------------------" << endl;
    //     cout << "\tBP07" << endl;
    //     cout << "\t- Date display added to" << endl;
    //     cout << "\t  navLayout" << endl;
    //     cout << "----------------------------------------" << endl;
    //     cout << "--------------------" << endl;
    //     cout << "For this:" << endl;
    //     cout << "--------------------" << endl;
    //     cout << "Size:" << endl;
    //     cout << "\tHeight: " << this->size().height() << endl;
    //     cout << "\tWidth: " << this->size().width() << endl << endl;
    //     cout << "--------------------" << endl;
    //     cout << "For layout:" << endl;
    //     cout << "--------------------" << endl;
    //     cout << "Size Hint:" << endl;
    //     cout << "\tHeight: " << layout->sizeHint().height() << endl;
    //     cout << "\tWidth: " << layout->sizeHint().width() << endl << endl;
    //     cout << "Minimum Size:" << endl;
    //     cout << "\tHeight: " << layout->minimumSize().height() << endl;
    //     cout << "\tWidth: " << layout->minimumSize().width() << endl << endl;
    //     cout << "Maximum Size:" << endl;
    //     cout << "\tHeight: " << layout->maximumSize().height() << endl;
    //     cout << "\tWidth: " << layout->maximumSize().width() << endl << endl;
    //     cout << "--------------------" << endl;
    //     cout << "For navLayout:" << endl;
    //     cout << "--------------------" << endl;
    //     cout << "Size Hint:" << endl;
    //     cout << "\tHeight: " << navLayout->sizeHint().height() << endl;
    //     cout << "\tWidth: " << navLayout->sizeHint().width() << endl << endl;
    //     cout << "Minimum Size:" << endl;
    //     cout << "\tHeight: " << navLayout->minimumSize().height() << endl;
    //     cout << "\tWidth: " << navLayout->minimumSize().width() << endl << endl;
    //     cout << "Maximum Size:" << endl;
    //     cout << "\tHeight: " << navLayout->maximumSize().height() << endl;
    //     cout << "\tWidth: " << navLayout->maximumSize().width() << endl << endl;
    // }
    // // DEBUG

    auto rightButton = new QPushButton(this);
    navLayout->addWidget(rightButton, 0, Qt::AlignRight);
    rightButton->setIcon(QIcon(":/icons/dateNavButtonRight.png"));
    rightButton->setIconSize(QSize(36,36));
    QObject::connect(rightButton, &QPushButton::clicked, this,
                     [this]() {
                         setActiveDate(m_activeDate.addDays(1));
    });
    rightButton->setToolTip("Go to next day.");
    // // DEBUG
    // {
    //     cout << "----------------------------------------" << endl;
    //     cout << "\tBP08" << endl;
    //     cout << "\t- Right button added to" << endl;
    //     cout << "\t  navLayout" << endl;
    //     cout << "----------------------------------------" << endl;
    //     cout << "--------------------" << endl;
    //     cout << "For this:" << endl;
    //     cout << "--------------------" << endl;
    //     cout << "Size:" << endl;
    //     cout << "\tHeight: " << this->size().height() << endl;
    //     cout << "\tWidth: " << this->size().width() << endl << endl;
    //     cout << "--------------------" << endl;
    //     cout << "For layout:" << endl;
    //     cout << "--------------------" << endl;
    //     cout << "Size Hint:" << endl;
    //     cout << "\tHeight: " << layout->sizeHint().height() << endl;
    //     cout << "\tWidth: " << layout->sizeHint().width() << endl << endl;
    //     cout << "Minimum Size:" << endl;
    //     cout << "\tHeight: " << layout->minimumSize().height() << endl;
    //     cout << "\tWidth: " << layout->minimumSize().width() << endl << endl;
    //     cout << "Maximum Size:" << endl;
    //     cout << "\tHeight: " << layout->maximumSize().height() << endl;
    //     cout << "\tWidth: " << layout->maximumSize().width() << endl << endl;
    //     cout << "--------------------" << endl;
    //     cout << "For navLayout:" << endl;
    //     cout << "--------------------" << endl;
    //     cout << "Size Hint:" << endl;
    //     cout << "\tHeight: " << navLayout->sizeHint().height() << endl;
    //     cout << "\tWidth: " << navLayout->sizeHint().width() << endl << endl;
    //     cout << "Minimum Size:" << endl;
    //     cout << "\tHeight: " << navLayout->minimumSize().height() << endl;
    //     cout << "\tWidth: " << navLayout->minimumSize().width() << endl << endl;
    //     cout << "Maximum Size:" << endl;
    //     cout << "\tHeight: " << navLayout->maximumSize().height() << endl;
    //     cout << "\tWidth: " << navLayout->maximumSize().width() << endl << endl;
    // }
    // // DEBUG


    layout->addSpacing(8);


    auto directives = new QGridLayout();
    layout->addLayout(directives);
    directives->setContentsMargins(16, 16, 16, 16);

    auto posTitle = new QLabel(this);
    directives->addWidget(posTitle, 0, 0);
    posTitle->setAlignment(Qt::Alignment(Qt::AlignHCenter | Qt::AlignTop));
    posTitle->setText("Positive Directives:");
    posTitle->setFont(QFont("Helvetica", 12, 1));

    auto negTitle = new QLabel(this);
    directives->addWidget(negTitle, 0, 2);
    negTitle->setAlignment(Qt::Alignment(Qt::AlignHCenter | Qt::AlignTop));
    negTitle->setText("Negative Directives:");
    negTitle->setFont(QFont("Helvetica", 12, 1));

    // auto posDs = new QVBoxLayout();
    // directives->addLayout(posDs, 1, 0);
    // auto negDs = new QVBoxLayout();
    // directives->addLayout(negDs, 1, 2);
    // // Drafting Final Functionality
    // QObject::connect(this, &DayFocus::activeDateChanged, this,
    //                  [this, posDs, negDs](const QDate& ad) {
    //     std::function<void(QLayout*)> clear;
    //     clear = [clear](QLayout* layout) {
    //         if (layout == nullptr) {
    //             return;
    //         }
    //         QLayoutItem* item;
    //         while((item = layout->takeAt(0))) {
    //             if (item->layout()) {
    //                 clear(item->layout());
    //                 delete item->layout();
    //             }
    //             if (item->widget()) {
    //                 delete item->widget();
    //             }
    //             delete item;
    //         }
    //     };

    //     clear(posDs);
    //     clear(negDs);

    //     // How to get data required to build a complete QLabel for each
    //     // positive and negative directive active for a specified day?
    // });
    // // Dummy Data
    // for (int p = 0; p < 6; p++) {
    //     auto dir = new QLabel(this);
    //     posDs->addWidget(dir);
    //     auto text = QString();
    //     text.setNum(p);
    //     text.prepend("Example Positive Directive no. ");
    //     dir->setText(text);
    //     dir->setToolTip("Description:\n\nExample description don't worry about it.");
    // }
    // for (int n = 0; n < 4; n++) {
    //     auto dir = new QLabel(this);
    //     negDs->addWidget(dir);
    //     auto text = QString();
    //     text.setNum(n);
    //     text.prepend("Example Negative Directive no. ");
    //     dir->setText(text);
    //     dir->setToolTip("Description:\n\nExample description but negative.");
    // }

    auto posDs = new QWidget(this);
    directives->addWidget(posDs, 1, 0);
    auto negDs = new QWidget(this);
    directives->addWidget(negDs, 1, 2);

    // auto posDView = new QListView(posDs);
    // auto negDView = new QListView(negDs);



    // auto directives = new QHBoxLayout();
    // layout->addLayout(directives);

    // directives->addSpacing(16);

    // auto posDs = new QVBoxLayout();
    // directives->addLayout(posDs);
    // auto posTitle = new QLabel(this);
    // posDs->addWidget(posTitle, 0, Qt::AlignCenter);
    // posTitle->setText("Positive Directives:");
    // posTitle->setFont(QFont("Helvetica", 12, 1));
    // posDs->addSpacing(8);
    // for (int p = 0; p < 6; p++) {
    //     auto dir = new QLabel(this);
    //     posDs->addWidget(dir);
    //     auto text = QString();
    //     text.setNum(p);
    //     text.prepend("Example Positive Directive no. ");
    //     dir->setText(text);
    //     dir->setToolTip("Description:\n\nExample description don't worry about it.");
    // }

    // directives->addSpacing(16);

    // auto negDs = new QVBoxLayout();
    // directives->addLayout(negDs);
    // auto negTitle = new QLabel(this);
    // negDs->addWidget(negTitle, 0, Qt::AlignCenter);
    // negTitle->setText("Negative Directives:");
    // negTitle->setFont(QFont("Helvetica", 12, 1));
    // negDs->addSpacing(8);
    // for (int n = 0; n < 4; n++) {
    //     auto dir = new QLabel(this);
    //     negDs->addWidget(dir);
    //     auto text = QString();
    //     text.setNum(n);
    //     text.prepend("Example Negative Directive no. ");
    //     dir->setText(text);
    //     dir->setToolTip("Description:\n\nExample description but negative.");
    // }

    // directives->addSpacing(16);


}

void DayFocus::setActiveDate(const QDate& ad)
{
    if (ad != QDate() && ad <= QDate::currentDate()) {
        m_activeDate = ad;
        emit activeDateChanged(m_activeDate);
    }
    return;
}

void DayFocus::setActiveProfile(const QSharedPointer<Profile>& ap)
{
    if (!ap.isNull()) {
        m_activeProfile = ap;
        emit activeProfileChanged(m_activeProfile);
    }
}
