// Room: /d/hhu/downroad.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
���������ںӺ���ѧУ�ڵ��������
    ���������¿ɵ��Ӻ����ţ�
    �򶫱����¿ɵ��Ӻ���ѧ��ͨ���ģ�
    ���ܷ羰������
LONG
	);
	set("item_desc", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"hhu1road2",
  "southwest" : __DIR__"hhu1road3",
]));
	set("no_clean_up", 0);

	setup();
}
