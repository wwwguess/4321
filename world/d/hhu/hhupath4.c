// Room: /d/hhu/hhupath4.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���������ںӺ���ѧУ�ڵ��������
    �����һ����ˮ���ݣ�һ���ǹ��̹�
    ���ܷ羰������
LONG
	);
	set("item_desc", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"hhupath3",
  "northwest" : __DIR__"hhucross",
]));
	set("no_clean_up", 0);

	setup();
}
