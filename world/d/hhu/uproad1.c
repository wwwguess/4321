// Room: /d/hhu/uproad1.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
���������ںӺ���ѧУ�ڵ��������
    ���ܷ羰������
LONG
	);
        set("objects",([
            __DIR__"npc/good_student":1,
        ]));
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"uproad",
  "northup" : __DIR__"hhuhill",
]));
	set("no_clean_up", 0);

	setup();
}
