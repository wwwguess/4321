// Room: /d/hhu/hhuhill.c

inherit ROOM;

void create()
{
	set("short", "ɽ��ƽ��");
	set("long", @LONG
���ǺӺ���ѧУ��һ��Сɽ��ɽ����
    ������һ��Ƭ��ƺ��lawn���������ǳ�������
    �����ǺӺ�����߽�����ѧ�ݣ������ǽ�ѧ¥��
    ���д������ʵĶ�������reading����
LONG
	);
	set("item_desc", ([ ]));
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"uproad1",
]));
        set("objects",([
            __DIR__"npc/obj/beer" : 1,
        ]));
	set("no_clean_up", 0);

	setup();
}
