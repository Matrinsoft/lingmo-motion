#pragma once

#include <QAbstractAnimation>

#include "export.h"

namespace Lingmo::Motion {

class LINGMO_MOTION_EXPORT SpringAnimation : public QAbstractAnimation {
    Q_OBJECT
    Q_PROPERTY(float mass READ mass WRITE setMass)
    Q_PROPERTY(float stiffness READ stiffness WRITE setStiffness)
    Q_PROPERTY(float damping READ damping WRITE setDamping)
    Q_PROPERTY(float from READ from WRITE setFrom)
    Q_PROPERTY(float to READ to WRITE setTo)

public:
    explicit SpringAnimation(QObject* parent = nullptr);

    float mass() const { return m_mass; }
    void setMass(float mass) { m_mass = mass; }

    float stiffness() const { return m_stiffness; }
    void setStiffness(float stiffness) { m_stiffness = stiffness; }

    float damping() const { return m_damping; }
    void setDamping(float damping) { m_damping = damping; }

    float from() const { return m_from; }
    void setFrom(float from) { m_from = from; }

    float to() const { return m_to; }
    void setTo(float to) { m_to = to; }

    float currentValue() const { return m_currentValue; }

    int duration() const override;

Q_SIGNALS:
    void valueChanged(float value);
    void finished();

protected:
    void updateCurrentTime(int currentTime) override;
    void updateState(QAbstractAnimation::State newState, QAbstractAnimation::State oldState) override;

private:
    float m_mass = 1.0f;
    float m_stiffness = 100.0f;
    float m_damping = 10.0f;
    float m_from = 0.0f;
    float m_to = 0.0f;
    float m_currentValue = 0.0f;
    float m_velocity = 0.0f;
    float m_initialVelocity = 0.0f;
};

} // namespace Lingmo::Motion
