// Room: /d/hhu/hhu3road1.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���������ںӺ���ѧУ�ڵ��������
    ���������Կ����Ӻ���������
    ���Ϸ����ǺӺ���ѧ�Ľ�ͨ���ġ�
    ���ܷ羰������
LONG
	);
	set("item_desc", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"hhucross",
  "northwest" : __DIR__"hhusport",
]));
	set("no_clean_up", 0);

	setup();
}
