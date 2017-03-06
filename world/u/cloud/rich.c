// Room: /u/cloud/rich.c

inherit ROOM;

void create()
{
	set("short", "�Ű����");
	set("long", @LONG
��������վ���Ű������
    �����ſڵĵط���һ����ľ��ɵ�����(sign)��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"m_house",
  "south" : __DIR__"eroad3",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/room_gua" : 5,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
