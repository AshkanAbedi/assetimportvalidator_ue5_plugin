import unreal
import sys
import os

def validate_texture(factory, created_object):
    if not isinstance(created_object, unreal.Texture2D):
        return

    asset_name = created_object.get_name()
    asset_path = created_object.get_path_name()

    if not asset_name.startswith("T_"):
        error_msg = f"Validation failed: '{asset_name}' does not start with 'T_'."
        unreal.log_error(error_msg)
        unreal.EditorAssetLibrary.delete_asset(asset_path)
        sys.exit(1)  # Fail CI

    width = created_object.get_size_x()
    height = created_object.get_size_y()
    if width != 1024 or height != 1024:
        error_msg = f"Validation failed: '{asset_name}' is {width}x{height}, expected 1024x1024."
        unreal.log_error(error_msg)
        unreal.EditorAssetLibrary.delete_asset(asset_path)
        sys.exit(1)  # Fail CI

    unreal.log(f"Validation passed for '{asset_name}'.")

import_subsystem = unreal.get_editor_subsystem(unreal.ImportSubsystem)
import_subsystem.on_asset_post_import.add_callable(validate_texture)

asset_tools = unreal.AssetToolsHelpers.get_asset_tools()
import_folder = unreal.Paths.project_content_dir() + "RawAssets/"
if os.path.exists(import_folder):
    for file in os.listdir(import_folder):
        if file.lower().endswith(('.png', '.jpg', '.tga')):
            full_path = os.path.join(import_folder, file).replace('\\', '/')
            task = unreal.AssetImportTask()
            task.set_editor_property('filename', full_path)
            task.set_editor_property('destination_path', '/Game/Textures')
            task.set_editor_property('save', True)
            task.set_editor_property('automated', True)
            asset_tools.import_asset_tasks([task])
else:
    unreal.log_warning("No test assets folder found; skipping import.")
    sys.exit(0)

unreal.log("All validations completed successfully.")
