#include "headers/StateMachine.h"

#include <utility>

namespace mario
{

void StateMachine::addState(StateRefT state, bool isReplacing)
{
    if (!m_states.empty() and isReplacing)
    {
        m_states.pop();
    }
    else
    {
        getActiveState()->pause();
    }

    m_states.push(std::move(state));
    getActiveState()->init();
}

void StateMachine::remoteState()
{
    if (!m_states.empty())
    {
        m_states.pop();
        getActiveState()->resume();
    }
}

StateRefT &StateMachine::getActiveState()
{
    return m_states.top();
}

} // namespace mario
