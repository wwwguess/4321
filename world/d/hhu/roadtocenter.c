// Room: /d/hhu/roadtocenter.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����·ͨ������������ģ��ǿ��ǺӺ���ѧ�е�ͨѶ��Ŧ����
    ���ܷ羰������
LONG
	);
	set("item_desc", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"hhupath3",
  "southup" : __DIR__"roadtocenter1",
]));
	set("no_clean_up", 0);

	setup();
}
