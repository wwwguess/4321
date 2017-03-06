// Room: /u/cloud/m_house.c

inherit ROOM;

void create()
{
	set("short", "�Ű����");
	set("long", @LONG
�������Ű���ĸ�լ�����˿ɽ�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"rich",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/millinare" : 1,
  __DIR__"npc/jiading" : 2,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
