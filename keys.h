static const Rule rules[] = {
	// class      instance      title    	        tags mask     isfloating   isterminal  noswallow  monitor
	{ "Gimp",       NULL,         NULL,             1,            0,          0,          0,          -1 },
	{ "Gimp",       NULL,         NULL,             1 << 8,       0,          0,          0,          -1 },
	{ TERMCLASS,    NULL,         NULL,       	    0,            0,          1,          0,           0 },
	{ NULL,         NULL,         "Event Tester",   0,            0,          0,          0,           1 },
	{ NULL,         "spterm",     NULL,       	    SPTAG(0),     1,          1,          0,           0 },
	{ NULL,         "key_pdf",    NULL,       	    0,			      1,          1,          1,           0 },
};

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
  { MODKEY,							                XK_F1,						spawn,					SHCMD("zathura ~/Singularis/aspects/dwm/keys.pdf") },

  // Open Applications
  { MODKEY,							                XK_Return,				spawn,					{.v = termcmd } },
  { MODKEY,                             XK_n,             spawn,          SHCMD(TERMINAL " -e 'nvim'") },
  { MODKEY,                             XK_b,             spawn,          SHCMD(TERMINAL " -e 'newsboat'") },
  { MODKEY,                             XK_m,             spawn,          SHCMD(TERMINAL " -e 'neomutt'") },
  { MODKEY,                             XK_c,             spawn,          SHCMD(TERMINAL " -e 'calcurse'") },
  { MODKEY,							                XK_e,							spawn,					SHCMD(TERMINAL " -e 'ncmpcpp'") },
  { MODKEY,							                XK_p,							spawn,					SHCMD(TERMINAL " -e 'castero'") },
  { MODKEY|ShiftMask,	                  XK_k,							spawn,					SHCMD(TERMINAL " -e 'kmon'") },
  { MODKEY|ShiftMask,		                XK_g,							spawn,					SHCMD(TERMINAL " -e 'gotop'") },
  { MODKEY|ShiftMask,		                XK_p,							spawn,					SHCMD(TERMINAL " -e 'pulsemixer'") },
  { MODKEY|ShiftMask,		                XK_b,							spawn,					SHCMD(TERMINAL " -e 'bashtop'") },
  { MODKEY|ShiftMask,		                XK_t,							spawn,					SHCMD(TERMINAL " -e 's-tui'") },
  { MODKEY|ShiftMask,		                XK_d,							spawn,					SHCMD("$HOME/Singularis/local/scripts/xmenu-script") },
  { MODKEY|ShiftMask,		                XK_z,							spawn,					SHCMD("zathura") },
  { MODKEY|ShiftMask,		                XK_s,							spawn,					SHCMD("tdrop -am -n 0 xfce4-terminal") },

  // Rofi bindings
  { MODKEY,                             XK_r,             spawn,          SHCMD("rofi -show drun -show-icons") },
  { MODKEY|ShiftMask,                   XK_r,             spawn,          SHCMD("rofi -show emoji -modi emoji") },
  { MODKEY|AltMask|ShiftMask,           XK_r,             spawn,          SHCMD("rofi -show window") },
  { MODKEY,							                XK_BackSpace,			spawn,					SHCMD("$HOME/.config/rofi/applets/menu/powermenu.sh") },
  
  // MPC specific keybindings
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

  // Dunst specific keybindings
  { ControlMask,		                    XK_space,					spawn,	        SHCMD("dunstctl close") },
  { ControlMask|ShiftMask,		          XK_space,					spawn,	        SHCMD("dunstctl close-all") },
  { ControlMask,		                    XK_grave,					spawn,	        SHCMD("dunstctl history-pop") },

  // School specific keybindings
  { MODKEY|AltMask,	 		                XK_c,							spawn,					SHCMD(SCHOOL_PATH "/main.py --change-course") },
  { MODKEY|AltMask,	 		                XK_l,							spawn,					SHCMD(SCHOOL_PATH "/main.py --lessons") },
  { MODKEY|AltMask,	 		                XK_g,							spawn,					SHCMD(SCHOOL_PATH "/main.py --grades") },
  { MODKEY|AltMask,	 		                XK_e,							spawn,					SHCMD(SCHOOL_PATH "/main.py --new-lesson") },
  { MODKEY|AltMask,	 		                XK_m,							spawn,					SHCMD(SCHOOL_PATH "/main.py --commands") },
  { MODKEY|AltMask,	 		                XK_p,							spawn,					SHCMD(SCHOOL_PATH "/main.py --projects") },
  { MODKEY|AltMask,	 		                XK_z,							spawn,					SHCMD(SCHOOL_PATH "/run-bash-scripts.py") },

  // Changing layouts
  { MODKEY|AltMask,							        XK_0,							setlayout,			{.v = &layouts[0]} },
  { MODKEY|AltMask,							        XK_1,							setlayout,			{.v = &layouts[1]} },
  { MODKEY|AltMask,							        XK_2,							setlayout,			{.v = &layouts[2]} },
  { MODKEY|AltMask,							        XK_3,							setlayout,			{.v = &layouts[3]} },
  { MODKEY|AltMask,							        XK_4,							setlayout,			{.v = &layouts[4]} },
  { MODKEY|AltMask,							        XK_5,							setlayout,			{.v = &layouts[5]} },
  { MODKEY|AltMask,							        XK_6,							setlayout,			{.v = &layouts[6]} },
  { MODKEY|AltMask,							        XK_7,							setlayout,			{.v = &layouts[7]} },
  { MODKEY|AltMask,							        XK_8,							setlayout,			{.v = &layouts[8]} },

  // DWM specific keybindings
  { MODKEY,							                XK_Tab,						view,						{0} },
  { MODKEY,							                XK_o,							incnmaster,			{.i = +1 } },
  { MODKEY|ShiftMask,		                XK_o,							incnmaster,			{.i = -1 } },
  { MODKEY,							                XK_q,							killclient,			{0} },
  { MODKEY|ShiftMask,                   XK_q,							spawn,					SHCMD("kill -HUP $(pidof -s dwm) && xdotool key Super_L") },
  { MODKEY|ShiftMask|AltMask,           XK_q,							quit,						{0} },
  { MODKEY|AltMask,                     XK_b,							togglebar,			{0} },
  { MODKEY|ShiftMask|AltMask,           XK_b,							spawn,					SHCMD("killall -q dwmblocks; dwmblocks &") },
  { MODKEY,							                XK_a,							togglegaps,			{0} },
  { MODKEY,							                XK_z,							incrgaps,				{.i = +3 } },
  { MODKEY,							                XK_x,							incrgaps,				{.i = -3 } },
  { MODKEY,							                XK_s,							togglesticky,		{0} },
  { MODKEY,							                XK_f,							togglefullscr,	{0} },
  { MODKEY,							                XK_h,							setmfact,				{.f = -0.05} },
  { MODKEY,							                XK_l,							setmfact,      	{.f = +0.05} },
  { MODKEY|ShiftMask,		                XK_semicolon,			shifttag,				{ .i = 1 } },
  { MODKEY,							                XK_Left,					focusmon,				{.i = -1 } },
  { MODKEY,							                XK_Right,					focusmon,				{.i = +1 } },
  { MODKEY|ShiftMask,		                XK_Left,					tagmon,					{.i = -1 } },
  { MODKEY|ShiftMask,		                XK_Right,					tagmon,					{.i = +1 } },
  { MODKEY,							                XK_space,					zoom,						{0} },
  { MODKEY|ShiftMask,		                XK_space,					togglefloating,	{0} },
};

