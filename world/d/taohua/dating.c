// Room: /d/new_taohua/dating.c

inherit ROOM;

void create()
{
	set("short", "大厅");
	set("long", @LONG
此厅名曰翠寒堂，廊下阶上摆满了茉莉，素馨等花。堂上又挂了伽兰
木等香珠，但觉馨意袭人，清芬满堂。堂中有一长案，几张椅子，桌上有些许
鲜果。此乃黄药师会客所在。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  
  "north": __DIR__"houting",
  "south" : __DIR__"qianting",
  
]));
	
   set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}
