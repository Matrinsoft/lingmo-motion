#include "lingmo-motion/springanimation.h"

#include <QtMath>

namespace Lingmo::Motion {

SpringAnimation::SpringAnimation(QObject* parent)
    : QAbstractAnimation(parent)
{
}

int SpringAnimation::duration() const
{
    return 1000;
}

void SpringAnimation::updateCurrentTime(int currentTime)
{
    Q_UNUSED(currentTime)

    float t = static_cast<float>(currentTime) / 1000.0f;
    float gamma = m_damping / (2.0f * m_mass);
    float omega = qSqrt(m_stiffness / m_mass - gamma * gamma);

    float target = m_to;
    float amplitude = target - m_from;

    if (qFuzzyIsNull(omega)) {
        m_currentValue = target - amplitude * (1.0f + gamma * t) * qExp(-gamma * t);
    } else {
        m_currentValue = target - amplitude * qExp(-gamma * t) *
            (qCos(omega * t) + (gamma / omega) * qSin(omega * t));
    }

    Q_EMIT valueChanged(m_currentValue);
}

void SpringAnimation::updateState(QAbstractAnimation::State newState, QAbstractAnimation::State oldState)
{
    Q_UNUSED(oldState)
    if (newState == QAbstractAnimation::Running) {
        m_currentValue = m_from;
    } else if (newState == QAbstractAnimation::Stopped) {
        Q_EMIT finished();
    }
}

} // namespace Lingmo::Motion
