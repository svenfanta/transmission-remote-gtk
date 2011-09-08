/*
 * transmission-remote-gtk - A GTK RPC client to Transmission
 * Copyright (C) 2011  Alan Fitton

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef _TRG_PREFS_H_
#define _TRG_PREFS_H_

#include <glib-object.h>
#include <json-glib/json-glib.h>

#define TRG_PREFS_FILENAME          "config.json"
#define TRG_PREFS_DEFAULT_DIR_MODE  448
#define TRG_PORT_DEFAULT            9091
#define TRG_INTERVAL_DEFAULT        3
#define TRG_MININTERVAL_DEFAULT        4
#define TRG_PROFILE_NAME_DEFAULT   "Default"

#define TRG_PREFS_KEY_PROFILE_ID    "profile-id"
#define TRG_PREFS_KEY_PROFILES    "profiles"
#define TRG_PREFS_KEY_PROFILE_NAME   "profile-name"
#define TRG_PREFS_KEY_HOSTNAME      "hostname"
#define TRG_PREFS_KEY_PORT          "port"
#define TRG_PREFS_KEY_MINUPDATE_INTERVAL "min-update-interval"
#define TRG_PREFS_KEY_USERNAME      "username"
#define TRG_PREFS_KEY_PASSWORD      "password"
#define TRG_PREFS_KEY_AUTO_CONNECT  "auto-connect"
#define TRG_PREFS_KEY_SSL            "ssl"
#define TRG_PREFS_KEY_UPDATE_INTERVAL "update-interval"
#define TRG_PREFS_KEY_COMPLETE_NOTIFY "complete-notify"
#define TRG_PREFS_KEY_ADD_NOTIFY    "add-notify"
#define TRG_PREFS_KEY_WINDOW_WIDTH  "window-width"
#define TRG_PREFS_KEY_WINDOW_HEIGHT "window-height"
#define TRG_PREFS_KEY_GRAPH_SPAN  "graph-span"
#define TRG_PREFS_KEY_SYSTEM_TRAY   "system-tray"
#define TRG_PREFS_KEY_SHOW_GRAPH    "show-graph"
#define TRG_PREFS_KEY_SYSTEM_TRAY_MINIMISE  "system-tray-minimise"
#define TRG_PREFS_KEY_FILTER_TRACKERS  "filter-trackers"
#define TRG_PREFS_KEY_FILTER_DIRS  "filter-dirs"
#define TRG_PREFS_KEY_SHOW_STATE_SELECTOR "show-state-selector"
#define TRG_PREFS_KEY_SHOW_NOTEBOOK "show-notebook"
#define TRG_PREFS_KEY_LAST_TORRENT_DIR "last-torrent-dir"
#define TRG_PREFS_KEY_ADD_OPTIONS_DIALOG "add-options-dialog"
#define TRG_PREFS_KEY_START_PAUSED "start-paused"
#define TRG_PREFS_KEY_UPDATE_ACTIVE_ONLY "update-active-only"
#define TRG_PREFS_KEY_DELETE_LOCAL_TORRENT "delete-local-torrent"
#define TRG_PREFS_STATE_SELECTOR_LAST "state-selector-last"

#define TRG_PREFS_KEY_TREE_VIEWS "tree-views"
#define TRG_PREFS_KEY_TV_SORT_TYPE "sort-type"
#define TRG_PREFS_KEY_TV_SORT_COL "sort-col"
#define TRG_PREFS_KEY_TV_COLUMNS "columns"
#define TRG_PREFS_KEY_TV_WIDTHS "widths"

#define TRG_PREFS_NOFLAGS    (1 << 0) /* 0x00 */
#define TRG_PREFS_GLOBAL     (1 << 1) /* 0x01 */
#define TRG_PREFS_PROFILE    (1 << 2) /* 0x02 */
#define TRG_PREFS_NEWNODE    (1 << 3) /* 0x04 */

G_BEGIN_DECLS

#define TRG_TYPE_PREFS trg_prefs_get_type()

#define TRG_PREFS(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST ((obj), TRG_TYPE_PREFS, TrgPrefs))

#define TRG_PREFS_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST ((klass), TRG_TYPE_PREFS, TrgPrefsClass))

#define TRG_IS_PREFS(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TRG_TYPE_PREFS))

#define TRG_IS_PREFS_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE ((klass), TRG_TYPE_PREFS))

#define TRG_PREFS_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS ((obj), TRG_TYPE_PREFS, TrgPrefsClass))

typedef struct {
  GObject parent;
} TrgPrefs;

typedef struct {
  GObjectClass parent_class;
} TrgPrefsClass;

GType trg_prefs_get_type (void);

TrgPrefs* trg_prefs_new (void);

void trg_prefs_add_default_int(TrgPrefs *p, gchar *key, int value);
void trg_prefs_add_default_string(TrgPrefs *p, gchar *key, gchar *value);
void trg_prefs_add_default_double(TrgPrefs *p, gchar *key, double value);
void trg_prefs_add_default_bool_true(TrgPrefs *p, gchar *key);

JsonNode *trg_prefs_get_value(TrgPrefs *p, gchar *key, int flags);
gchar *trg_prefs_get_string(TrgPrefs *p, gchar *key, int flags);
int trg_prefs_get_int(TrgPrefs *p, gchar *key, int flags);
gdouble trg_prefs_get_double(TrgPrefs *p, gchar *key, int flags);
gboolean trg_prefs_get_bool(TrgPrefs *p, gchar *key, int flags);
JsonObject* trg_prefs_get_profile(TrgPrefs *p);
JsonArray* trg_prefs_get_profiles(TrgPrefs *p);
gint trg_prefs_get_profile_id(TrgPrefs *p);
void trg_prefs_del_profile(TrgPrefs *p, JsonObject *profile);
void trg_prefs_set_profile(TrgPrefs *p, JsonObject *profile);
JsonObject *trg_prefs_new_profile(TrgPrefs *p);
JsonObject *trg_get_current_profile(TrgPrefs *p);
JsonObject *trg_prefs_get_root(TrgPrefs *p);

void trg_prefs_set_int(TrgPrefs *p, gchar *key, int value, int flags);
void trg_prefs_set_string(TrgPrefs *p, gchar *key, const gchar *value, int flags);
void trg_prefs_set_double(TrgPrefs *p, gchar *key, double value, int flags);
void trg_prefs_set_bool(TrgPrefs *p, gchar *key, gboolean value, int flags);

gboolean trg_prefs_save(TrgPrefs *p);
void trg_prefs_load(TrgPrefs *p);

guint trg_prefs_get_add_flags(TrgPrefs *p);

G_END_DECLS

#endif /* _TRG_PREFS_H_ */