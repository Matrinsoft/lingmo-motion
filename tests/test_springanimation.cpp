#include <QtTest/QtTest>
#include <QCoreApplication>

#include "lingmo-motion/springanimation.h"

class TestSpringAnimation : public QObject {
    Q_OBJECT

private slots:
    void testDefaults();
    void testParameters();
    void testAnimation();

private:
};

void TestSpringAnimation::testDefaults()
{
    Lingmo::Motion::SpringAnimation anim;
    QCOMPARE(anim.mass(), 1.0f);
    QCOMPARE(anim.stiffness(), 100.0f);
    QCOMPARE(anim.damping(), 10.0f);
    QCOMPARE(anim.from(), 0.0f);
    QCOMPARE(anim.to(), 0.0f);
    QCOMPARE(anim.currentValue(), 0.0f);
}

void TestSpringAnimation::testParameters()
{
    Lingmo::Motion::SpringAnimation anim;
    anim.setMass(2.0f);
    anim.setStiffness(200.0f);
    anim.setDamping(5.0f);
    anim.setFrom(10.0f);
    anim.setTo(100.0f);

    QCOMPARE(anim.mass(), 2.0f);
    QCOMPARE(anim.stiffness(), 200.0f);
    QCOMPARE(anim.damping(), 5.0f);
    QCOMPARE(anim.from(), 10.0f);
    QCOMPARE(anim.to(), 100.0f);
}

void TestSpringAnimation::testAnimation()
{
    Lingmo::Motion::SpringAnimation anim;
    anim.setFrom(0.0f);
    anim.setTo(100.0f);
    anim.setMass(1.0f);
    anim.setStiffness(100.0f);
    anim.setDamping(10.0f);

    QSignalSpy valueSpy(&anim, &Lingmo::Motion::SpringAnimation::valueChanged);
    anim.start();
    QTest::qWait(1100);

    QVERIFY(valueSpy.count() > 0);
    QVERIFY(qAbs(anim.currentValue() - 100.0f) < 1.0f);
}

QTEST_MAIN(TestSpringAnimation)
#include "test_springanimation.moc"
