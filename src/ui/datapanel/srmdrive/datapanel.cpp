#include "datapanel.h"


namespace ui {
namespace srmdrive {


void DataPanel::draw(bool& open) {
    ImGui::Begin("Data", &open);
    _draw_watch_table();
    ImGui::NewLine();
    _draw_tpdo1_table();
    ImGui::NewLine();
    _draw_tpdo2_table();
    ImGui::NewLine();
    _draw_tpdo3_table();
    ImGui::NewLine();
    _draw_tpdo4_table();
    ImGui::End();
}


void DataPanel::_draw_watch_table() {
    static ImGuiTableFlags flags = ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg;
    if (ImGui::BeginTable("watch_table", 2, flags)) {
        ImGui::TableSetupColumn("Parameter");
        ImGui::TableSetupColumn("Value");
        ImGui::TableHeadersRow();

        const auto& watch_objects = _server->watch_service.objects();

        for (int row = 0; row < watch_objects.size(); ++row) {
            ImGui::TableNextRow();
            ImGui::TableSetColumnIndex(0);
            ImGui::Text("%s [%s]", watch_objects[row]->name.c_str(), watch_objects[row]->unit.c_str());
            ImGui::TableSetColumnIndex(1);
            ImGui::TextUnformatted(_server->watch_service.value_str(watch_objects[row]->subcategory, watch_objects[row]->name).c_str());
        }
        ImGui::EndTable();
    }
}


void DataPanel::_draw_tpdo1_table() {
    static ImGuiTableFlags flags = ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg;
    if (ImGui::BeginTable("watch_table", 2, flags)) {
        ImGui::TableSetupColumn("Parameter");
        ImGui::TableSetupColumn("Value");
        ImGui::TableHeadersRow();

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Connection");
        ImGui::TableSetColumnIndex(1);
        _server->tpdo_service.is_ok(ucanopen::CobTpdo::tpdo1) ? ImGui::TextUnformatted("ok") : ImGui::TextUnformatted("bad");

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Raw Data [hex]");
        ImGui::TableSetColumnIndex(1);
        auto payload = _server->tpdo_service.data(ucanopen::CobTpdo::tpdo1);
        ImGui::Text("%02X %02X %02X %02X %02X %02X %02X %02X", payload[0], payload[1], payload[2], payload[3], payload[4], payload[5], payload[6], payload[7]);

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Drive State");
        ImGui::TableSetColumnIndex(1);
        ImGui::TextUnformatted(_server->tpdo1().drive_state.c_str());

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Run [bool]");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%d", _server->tpdo1().run);

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Error [bool]");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%d", _server->tpdo1().error);

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Warning [bool]");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%d", _server->tpdo1().warning);

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Overheat [bool]");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%d", _server->tpdo1().overheat);

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Control Mode");
        ImGui::TableSetColumnIndex(1);
        ImGui::TextUnformatted(_server->tpdo1().ctlmode.c_str());

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Control Loop");
        ImGui::TableSetColumnIndex(1);
        ImGui::TextUnformatted(_server->tpdo1().ctlloop.c_str());

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Torque [Nm]");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%d",_server->tpdo1().torque);

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Speed [rpm]");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%d",_server->tpdo1().speed);

        ImGui::EndTable();
    }
}


void DataPanel::_draw_tpdo2_table() {
    static ImGuiTableFlags flags = ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg;
    if (ImGui::BeginTable("watch_table", 2, flags)) {
        ImGui::TableSetupColumn("Parameter");
        ImGui::TableSetupColumn("Value");
        ImGui::TableHeadersRow();

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Connection");
        ImGui::TableSetColumnIndex(1);
        _server->tpdo_service.is_ok(ucanopen::CobTpdo::tpdo2) ? ImGui::TextUnformatted("ok") : ImGui::TextUnformatted("bad");

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Raw Data [hex]");
        ImGui::TableSetColumnIndex(1);
        auto payload = _server->tpdo_service.data(ucanopen::CobTpdo::tpdo2);
        ImGui::Text("%02X %02X %02X %02X %02X %02X %02X %02X", payload[0], payload[1], payload[2], payload[3], payload[4], payload[5], payload[6], payload[7]);

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("DC Voltage [V]");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%d",_server->tpdo2().dc_voltage);

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Stator Current [A]");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%d",_server->tpdo2().stator_current);

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Field Current [A]");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%.1f",_server->tpdo2().field_current);

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Mech Power [kW]");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%d",_server->tpdo2().mech_power);

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Manual Field Current [bool]");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%d",_server->tpdo2().manual_field_current);

        ImGui::EndTable();
    }
}


void DataPanel::_draw_tpdo3_table() {
    static ImGuiTableFlags flags = ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg;
    if (ImGui::BeginTable("watch_table", 2, flags)) {
        ImGui::TableSetupColumn("Parameter");
        ImGui::TableSetupColumn("Value");
        ImGui::TableHeadersRow();

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Connection");
        ImGui::TableSetColumnIndex(1);
        _server->tpdo_service.is_ok(ucanopen::CobTpdo::tpdo3) ? ImGui::TextUnformatted("ok") : ImGui::TextUnformatted("bad");

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Raw Data [hex]");
        ImGui::TableSetColumnIndex(1);
        auto payload = _server->tpdo_service.data(ucanopen::CobTpdo::tpdo3);
        ImGui::Text("%02X %02X %02X %02X %02X %02X %02X %02X", payload[0], payload[1], payload[2], payload[3], payload[4], payload[5], payload[6], payload[7]);

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("PWR Temperature [°C]");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%d",_server->tpdo3().pwrmodule_temp);

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("EXC Temperature [°C]");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%d",_server->tpdo3().excmodule_temp);

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("PCB Temperature [°C]");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%d",_server->tpdo3().pcb_temp);

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("AW Temperature [°C]");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%d",_server->tpdo3().aw_temp);

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("FW Temperature [°C]");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%d",_server->tpdo3().fw_temp);

        ImGui::EndTable();
    }    
}


void DataPanel::_draw_tpdo4_table() {
    static ImGuiTableFlags flags = ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg;
    if (ImGui::BeginTable("watch_table", 2, flags)) {
        ImGui::TableSetupColumn("Parameter");
        ImGui::TableSetupColumn("Value");
        ImGui::TableHeadersRow();

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Connection");
        ImGui::TableSetColumnIndex(1);
        _server->tpdo_service.is_ok(ucanopen::CobTpdo::tpdo4) ? ImGui::TextUnformatted("ok") : ImGui::TextUnformatted("bad");

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Raw Data [hex]");
        ImGui::TableSetColumnIndex(1);
        auto payload = _server->tpdo_service.data(ucanopen::CobTpdo::tpdo4);
        ImGui::Text("%02X %02X %02X %02X %02X %02X %02X %02X", payload[0], payload[1], payload[2], payload[3], payload[4], payload[5], payload[6], payload[7]);

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Errors");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%d",_server->errors());

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Warnings");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%d",_server->warnings());

        ImGui::EndTable();
    }  
}


} // namespace srmdrive
} // namespace ui
