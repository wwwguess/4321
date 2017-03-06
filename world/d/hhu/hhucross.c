// Room: /d/hhu/hhucross.c

inherit ROOM;

void create()
{
	set("short", "�Ӻ���ѧ��ͨ����");
	set("long", @LONG
�ɴ����ϵ��Ӻ����ţ����ţ����򶫱����Ӻ������ţ�
    �ɴ������ϵ��Ӻ����ţ����������Ӻ���������
    ������һ������(statue)������ͨ��Ӻ���ѧ�ݡ�
    ���ܷ羰������
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "statue" : "���ǺӺ���ѧУ������������������ҹ��������޲��׼������ҡ�
",
]));
	set("exits", ([ /* sizeof() == 5 */
  "northeast" : __DIR__"hhu2road1",
  "southeast" : __DIR__"hhupath4",
  "northup" : __DIR__"uproad",
  "northwest" : __DIR__"hhu3road1",
  "southwest" : __DIR__"hhu1road1",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/msg_student" : 1,
]));
	set("no_clean_up", 0);

	setup();
}
