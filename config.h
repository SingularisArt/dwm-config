/* See LICENSE file for copyright and license details. */

/* Constants */
#define TERMINAL "xfce4-terminal"
#define TERMCLASS "St"
#define BROWSER "google-chrome-stable"
#define FILEBROWSER "nautilus"
#define AltMask Mod1Mask
#define PDF_VIEWER "zathura"
#define CURRENTCOURSE "~/Documents/notes/current-course"

/* appearance */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const double defaultopacity  = 0.75;

static unsigned int borderpx        = 3;
static unsigned int snap            = 32;
static unsigned int gappih          = 20;
static unsigned int gappiv          = 10;
static unsigned int gappoh          = 10;
static unsigned int gappov          = 30;
static int swallowfloating          = 0;
static int smartgaps                = 0;

//static const char *fonts[]          = { "Noto Color Emoji:size=10",
static const char *fonts[]          = { "monospace:size=9",
                                        "fontawesome:size=9",
                                        "JoyPixels:pixelsize=9" };
static const char dmenufont[]			  = "monospace:size=12";

#include "/home/hashem/.cache/wal/colors-wal-dwm.h"

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = { TERMINAL, "-n", "spterm", "-g", "120x34", NULL };
const char *spcmd2[] = { TERMINAL, "-n", "spcalc", "-f", "monospace:size=16", "-g", "80x80", "-e", "bc", "-lq", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",      spcmd1},
	{"spcalc",      spcmd2},
};

/* tagging */
static const char *tags[] = { "T", "W", "F", "B", "P", "A", "E", "S", "C" };

static const Rule rules[] = {
	// class   instance   title    	tags mask    isfloating   isterminal  noswallow  monitor
	{ "Gimp",  NULL,      NULL,     1,           0,           0,          0,         -1 },
	{ "Gimp",  NULL,      NULL,     1 << 8,      0,           0,          0,         -1 },
};

/* layout(s) */
static float mfact     = 0.55;
static int nmaster     = 1;
static int resizehints = 0;
#define FORCE_VSPLIT 1
#include "vanitygaps.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "MIDDLE",	centeredmaster },

	{ "Fibonacci",	spiral },
	{ "DWINDLE",	dwindle },

	{ "NULL",	NULL },
	{ NULL,		NULL },

};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define STACKKEYS(MOD,ACTION) \
	{ MOD,	XK_j,	ACTION##stack,	{.i = INC(+1) } }, \
	{ MOD,	XK_k,	ACTION##stack,	{.i = INC(-1) } }, \
	{ MOD,  XK_v,   ACTION##stack,  {.i = 0 } }, \

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[]  = { TERMINAL, NULL };
static const char *filemanager[]  = { FILEBROWSER, NULL };

/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
	{ "color0",						STRING,		&norm_border },
	{ "color8",						STRING,		&sel_border },
	{ "color0",						STRING,		&norm_bg },
	{ "color4",						STRING,		&norm_fg },
	{ "color0",						STRING,		&sel_fg },
	{ "color4",						STRING,		&sel_bg },
	{ "borderpx",					INTEGER,	&borderpx },
	{ "snap",							INTEGER,	&snap },
	{ "showbar",					INTEGER,	&showbar },
	{ "topbar",						INTEGER,	&topbar },
	{ "nmaster",					INTEGER,	&nmaster },
	{ "resizehints",			INTEGER,	&resizehints },
	{ "mfact",						FLOAT,		&mfact },
	{ "gappih",						INTEGER,	&gappih },
	{ "gappiv",						INTEGER,	&gappiv },
	{ "gappoh",						INTEGER,	&gappoh },
	{ "gappov",						INTEGER,	&gappov },
	{ "swallowfloating",	INTEGER,	&swallowfloating },
	{ "smartgaps",				INTEGER,	&smartgaps },
};

#include <X11/XF86keysym.h>
#include "shiftview.c"

static Key keys[] = {
  STACKKEYS(MODKEY,                          focus)
  STACKKEYS(MODKEY|ShiftMask,                push)
  TAGKEYS(			XK_1,		0)
  TAGKEYS(			XK_2,		1)
  TAGKEYS(			XK_3,		2)
  TAGKEYS(			XK_4,		3)
  TAGKEYS(			XK_5,		4)
  TAGKEYS(			XK_6,		5)
  TAGKEYS(			XK_7,		6)
  TAGKEYS(			XK_8,		7)
  TAGKEYS(			XK_9,		8)
  { MODKEY,							                XK_w,							spawn,					SHCMD(BROWSER) },
  { MODKEY,							                XK_F1,						spawn,					SHCMD("zathura ~/Singularis/master.pdf") },
  { MODKEY,							                XK_BackSpace,			spawn,					SHCMD("$HOME/.config/rofi/applets/menu/powermenu.sh") },
  { MODKEY,							                XK_d,							spawn,					SHCMD("rofi -show drun -show-icons") },
  { MODKEY|ShiftMask,		                XK_e,							spawn,					SHCMD("rofi -show emoji -modi emoji") },
  { MODKEY|ShiftMask,		                XK_a,							spawn,					SHCMD("$HOME/.config/rofi/applets/applets/apps.sh") },
  { MODKEY,							                XK_0,							view,						{.ui = ~0 } },
  { MODKEY|ShiftMask,		                XK_0,							tag,						{.ui = ~0 } },

  { MODKEY,							                XK_Tab,						view,						{0} },
  { MODKEY,							                XK_q,							killclient,			{0} },
  { MODKEY,							                XK_t,							setlayout,			{.v = &layouts[0]} },
  { MODKEY,							                XK_y,							setlayout,			{.v = &layouts[1]} },
  { MODKEY,							                XK_u,							setlayout,			{.v = &layouts[2]} },
  { MODKEY,							                XK_i,							setlayout,			{.v = &layouts[3]} },
  { MODKEY,							                XK_T,							setlayout,			{.v = &layouts[4]} },
  { MODKEY,							                XK_o,							incnmaster,			{.i = +1 } },
  { MODKEY,							                XK_backslash,			view,						{0} },
  { MODKEY|ShiftMask,		                XK_o,							incnmaster,			{.i = -1 } },
  { MODKEY|ShiftMask,                   XK_q,							quit,						{0} },
  { MODKEY,							                XK_a,							togglegaps,			{0} },
  { MODKEY,							                XK_s,							togglesticky,		{0} },
  { MODKEY,							                XK_f,							togglefullscr,	{0} },
  { MODKEY,							                XK_g,							shiftview,			{ .i = -1 } },
  { MODKEY,							                XK_h,							setmfact,				{.f = -0.05} },
  { MODKEY,							                XK_l,							setmfact,      	{.f = +0.05} },
  { MODKEY,							                XK_semicolon,			shiftview,			{ .i = 1 } },
  { MODKEY,							                XK_apostrophe,		togglescratch,	{.ui = 1} },
  { MODKEY,							                XK_Return,				spawn,					{.v = termcmd } },
  { MODKEY|ShiftMask,		                XK_g,							shifttag,				{ .i = -1 } },
  { MODKEY|ShiftMask,		                XK_semicolon,			shifttag,				{ .i = 1 } },
  { MODKEY|ShiftMask,		                XK_Return,				togglescratch,	{.ui = 0} },

  { MODKEY|ShiftMask,		                XK_a,				      spawn,	        SHCMD("$HOME/Singularis/local/scripts/anime") },
  { MODKEY|ShiftMask,		                XK_n,				      spawn,	        SHCMD("$HOME/Singularis/local/scripts/netflix") },
  { MODKEY|ShiftMask,		                XK_u,				      spawn,	        SHCMD("$HOME/Singularis/local/scripts/search") },
  { MODKEY|ShiftMask,		                XK_m,				      spawn,	        SHCMD("$HOME/Singularis/local/scripts/music") },

  { MODKEY,							                XK_n,							spawn,					SHCMD(TERMINAL " -e nvim") },
  { MODKEY,							                XK_m,							spawn,					SHCMD(TERMINAL " -e neomutt") },
  { MODKEY,							                XK_e,							spawn,					SHCMD(TERMINAL " -e ncmpcpp") },
  { MODKEY,							                XK_c,							spawn,					SHCMD(TERMINAL " -e calcurse") },
  { MODKEY|ShiftMask,	                  XK_k,							spawn,					SHCMD(TERMINAL " -e sudo kmon") },
  { MODKEY|ShiftMask,		                XK_y,							spawn,					SHCMD(TERMINAL " -e sudo ytop") },
  { MODKEY|ShiftMask,		                XK_p,							spawn,					SHCMD(TERMINAL " -e pavucontrol") },
  { MODKEY|ShiftMask,		                XK_b,							spawn,					SHCMD(TERMINAL " -e bashtop") },
  { MODKEY|ShiftMask,		                XK_w,							spawn,					SHCMD(TERMINAL " -e newsboat") },
  { MODKEY|ShiftMask,		                XK_r,							spawn,					SHCMD(TERMINAL " -e htop") },
  { MODKEY|ControlMask,		              XK_d,							spawn,					SHCMD("$HOME/Singularis/local/scripts/xmenu-script") },
  { MODKEY|ControlMask,		              XK_s,							spawn,					SHCMD("tdrop -am -n 0 xfce4-terminal") },

  { MODKEY,							                XK_z,							incrgaps,				{.i = +3 } },
  { MODKEY,							                XK_x,							incrgaps,				{.i = -3 } },
  { MODKEY,							                XK_b,							togglebar,			{0} },

  { MODKEY|AltMask,  		                XK_t,							spawn,					SHCMD("mpc toggle") },
  { MODKEY|AltMask,  		                XK_r,				      spawn,					SHCMD("mpc seek 0") },
  { MODKEY|AltMask|ShiftMask,		        XK_bracketleft,		spawn,					SHCMD("mpc seek +60") },
  { MODKEY|AltMask|ShiftMask,		        XK_bracketright,	spawn,					SHCMD("mpc seek -60") },
  { MODKEY|AltMask,							        XK_bracketleft,		spawn,					SHCMD("mpc seek +10") },
  { MODKEY|AltMask,							        XK_bracketright,	spawn,					SHCMD("mpc seek -10") },
  { MODKEY|AltMask,			                XK_comma,					spawn,					SHCMD("mpc prev") },
  { MODKEY|AltMask,			                XK_period,				spawn,					SHCMD("mpc next") },
  { MODKEY|AltMask,	                    XK_u,				      spawn,					SHCMD("pamixer -i 5 && $HOME/Singularis/local/scripts/volume-indicator show") },
  { MODKEY|AltMask,	                    XK_d,				      spawn,					SHCMD("pamixer -d 5 && $HOME/Singularis/local/scripts/volume-indicator show") },
  { MODKEY|AltMask,  		                XK_v,							spawn,					SHCMD("$HOME/.config/rofi/applets/applets/mpd.sh") },

  { MODKEY,							                XK_Left,					focusmon,				{.i = -1 } },
  { MODKEY,							                XK_Right,					focusmon,				{.i = +1 } },
  { MODKEY|ShiftMask,		                XK_Left,					tagmon,					{.i = -1 } },
  { MODKEY|ShiftMask,		                XK_Right,					tagmon,					{.i = +1 } },

  { MODKEY|AltMask,	 		                XK_c,							spawn,					SHCMD("python3.10 $HOME/Singularis/local/scripts/school/rofi-current-course.py") },
  { MODKEY|AltMask,	 		                XK_l,							spawn,					SHCMD("python3.10 $HOME/Singularis/local/scripts/school/rofi-lessons.py") },
  { MODKEY|AltMask,	 		                XK_g,							spawn,					SHCMD("python3.10 $HOME/Singularis/local/scripts/school/rofi-grades.py") },
  { MODKEY|AltMask,	 		                XK_e,							spawn,					SHCMD("python3.10 $HOME/Singularis/local/scripts/school/rofi-new-lesson.py") },
  { MODKEY|AltMask,	 		                XK_p,							spawn,					SHCMD("python3.10 $HOME/Singularis/local/scripts/school/rofi-commands.py") },
  { MODKEY|AltMask,	 		                XK_y,							spawn,					SHCMD("$HOME/Singularis/local/scripts/school/rofi-yaml.sh") },
  { MODKEY|AltMask,	 		                XK_n,							spawn,					SHCMD("$HOME/Singularis/local/scripts/school/rofi-nvim.sh") },
  { MODKEY|AltMask,	 		                XK_s,							spawn,					SHCMD("$HOME/Singularis/local/scripts/school/rofi-source-code.sh") },
  { MODKEY|AltMask,	 		                XK_w,							spawn,					SHCMD("$HOME/Singularis/local/scripts/school/rofi-web-browser.sh") },
  { MODKEY|AltMask,	 		                XK_f,							spawn,					SHCMD("$HOME/Singularis/local/scripts/school/rofi-file-browser.sh") },
  { MODKEY|AltMask,	 		                XK_i,							spawn,					SHCMD("$HOME/Singularis/local/scripts/school/rofi-inkscape.sh") },
  { MODKEY|AltMask,	 		                XK_z,							spawn,					SHCMD("$HOME/Singularis/local/scripts/school/rofi-zathura.sh") },
  { MODKEY|AltMask,	 		                XK_o,							spawn,					SHCMD("$HOME/Singularis/local/scripts/school/rofi-compile.sh") },

  { MODKEY|ShiftMask,		                XK_s,	            spawn,	        SHCMD("transset-df -a --dec .1") },
  { MODKEY|ShiftMask,		                XK_d,	            spawn,	        SHCMD("transset-df -a --inc .1") },
  { MODKEY|ShiftMask,		                XK_f,	            spawn,	        SHCMD("transset-df -a .9") },

  { MODKEY,							                XK_space,					zoom,						{0} },
  { MODKEY|ShiftMask,		                XK_space,					togglefloating,	{0} },

  { ControlMask,		                    XK_space,					spawn,	        SHCMD("dunstctl close") },
  { ControlMask|ShiftMask,		          XK_space,					spawn,	        SHCMD("dunstctl close-all") },
  { ControlMask,		                    XK_grave,					spawn,	        SHCMD("dunstctl history-pop") },
};

static Button buttons[] = {
#ifndef __OpenBSD__
  { ClkWinTitle,          0,              Button2,        zoom,           {0} },
  { ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
  { ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
  { ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
  { ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
  { ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
  { ClkStatusText,        ShiftMask,      Button1,        sigdwmblocks,   {.i = 6} },
#endif
  { ClkStatusText,        ShiftMask,      Button3,        spawn,          SHCMD(TERMINAL " -e nvim ~/.local/src/dwmblocks/config.h") },
  { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
  { ClkClientWin,         MODKEY,         Button2,        defaultgaps,	  {0} },
  { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
  { ClkClientWin,					MODKEY,					Button4,				incrgaps,	{.i = +1} },
  { ClkClientWin,					MODKEY,					Button5,				incrgaps,	{.i = -1} },
  { ClkTagBar,            0,              Button1,        view,           {0} },
  { ClkTagBar,            0,              Button3,        toggleview,     {0} },
  { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
  { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
  { ClkTagBar,						0,							Button4,				shiftview,			{.i = -1} },
  { ClkTagBar,						0,							Button5,				shiftview,			{.i = 1} },
  { ClkRootWin,						0,							Button2,				togglebar,			{0} },
};

