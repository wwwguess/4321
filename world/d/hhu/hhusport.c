// Room: /d/hhu/hhusport.c

inherit ROOM;

void create()
{
	set("short", "�Ӻ�������");
	set("long", @LONG
�����������Ӻ���ѧ����������
    ��������һƬ������ľ���
    �ɴ����Ͽ��Ե��Ӻ���ѧ�Ľ�ͨ���ġ�
LONG
	);
	set("item_desc", ([ ]));
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"studentroom3",
  "southeast" : __DIR__"hhu3road1",
]));
	set("no_clean_up", 0);

	setup();
}
