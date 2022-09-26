#include "ControlsDialog.h"

#include "GuardZone.h"
#include "MessageBox.h"
#include "RadarMarpa.h"
#include "RadarPanel.h"

// need to disable funtion in ControlDialogs.cpp; line 1520-1537


void ControlsDialog::OnTransmitButtonClick(wxCommandEvent& event) {
  RadarState state = (RadarState)m_ri->m_state.GetButton();
  SetMenuAutoHideTimeout();

  // If we already have a running timer, then turn timed_idle_mode off
  if (m_ri->m_next_state_change.GetValue() > 1 &&
      (m_ri->m_timed_idle_hardware || m_ri->m_idle_transmit > 0 || m_ri->m_idle_standby > 0)) {
    m_timed_idle_button->SetState(RCS_OFF);
  }
  if (state == RADAR_STANDBY || state == RADAR_STOPPING || state == RADAR_SPINNING_DOWN)
  m_stayalive_timeout = 0;  // Allow immediate restart of any TxOn or TxOff command
  void RadarTxOn()
  {
    //m_ri->RequestRadarState(RADAR_TRANSMIT); -ori
    m_ri->RequestRadarState(RADAR_STANDBY);
  } else {
    //m_ri->RequestRadarState(RADAR_STANDBY); -ori
    m_ri->RequestRadarState(RADAR_TRANSMIT);
  }
}
