// Room: /d/mingjiao/nongjia.c

inherit ROOM;

void create()
{
	set("short", "ũ��");
	set("long", @LONG
����һ��ũ��ס�ķ��ӣ�������խ��
�����������ҵضѷ���Щ���·���
һ��ũ������ɨ�ء�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"nongjia2",
  "east" : __DIR__"xiaozhen",
]));
	set("no_clean_up", 0);
set("objects",([
__DIR__"npc/woman" :1,
]));

	setup();
	replace_program(ROOM);
}

