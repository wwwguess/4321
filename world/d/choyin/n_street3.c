// Room: /d/choyin/n_street3.c

inherit ROOM;

void create()
{
	set("short", "���ִ��");
	set("long", @LONG
������������һ�����Ĵ���ϣ��ֵ������߱�ֱ�����죬�ϱ���
��һ��¡���ʯ̨������Կ���ʯ̨ǰ�п�ʯ�������顸�����ء�����
���֣��ֵ��Ķ��ߺ����߶���ʯ��յأ�Χ���������س�Ϊһ��Բ����
���С�����̶��ۼ������ｻ��������
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"nw_street",
  "north" : __DIR__"n_street2",
  "south" : __DIR__"tree_tomb",
]));
	set("objects", ([
		__DIR__"npc/dumpling_seller": 1
	]) );
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
