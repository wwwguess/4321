// Room: /d/hhu/hhu1road3.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���������ںӺ���ѧУ�ڵ��������
    ·���ǺӺ���ѧ��ѧ���ǣ�
    ·���ǺӺ���ѧ������¥��
    ���������������Ӻ���ѧ�����ţ�
    ������ѧ��������ͨ����
    ���ܷ羰������
LONG
	);
	set("item_desc", ([ ]));
	set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"downroad",
  "west" : __DIR__"hhugate_west",
  "south" : __DIR__"students",
  "north" : __DIR__"studentroom1",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/student_1" : 2,
  __DIR__"npc/student_2" : 1,
]));
	set("no_clean_up", 0);

	setup();
}
