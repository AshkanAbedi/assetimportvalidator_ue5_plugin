import unreal

def validate_texture(factory, created_object):
    if not isinstance(created_object, unreal.Texture2D):
        return

    asset_name = created_object.get_name()
    asset_path = created_object.get_path_name()

    if not asset_name.startswith("T_"):
        error_msg = f"Imported texture '{asset_name}' does not start with 'T_'. Import failed."
        unreal.log_error(error_msg)
        unreal.EditorDialog.show_message("Import Validation Error", error_msg, unreal.AppMsgType.OK)
        unreal.EditorAssetLibrary.delete_asset(asset_path)
        return

    width = created_object.blueprint_get_size_x()
    height = created_object.blueprint_get_size_y()
    if width != 1024 or height != 1024:
        error_msg = f"Imported texture '{asset_name}' resolution is {width}x{height}, not 1024x1024. Import failed."
        unreal.log_error(error_msg)
        unreal.EditorDialog.show_message("Import Validation Error", error_msg, unreal.AppMsgType.OK)
        unreal.EditorAssetLibrary.delete_asset(asset_path)
        return

    unreal.log(f"Texture '{asset_name}' imported successfully: Valid name and 1024x1024 resolution.")

import_subsystem = unreal.get_editor_subsystem(unreal.ImportSubsystem)
import_subsystem.on_asset_post_import.add_callable(validate_texture)

unreal.log("Texture import validator bound successfully.")
