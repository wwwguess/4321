inherit ROOM;

void create()
{
   set("short", "����ׯ����");
	set("long", @LONG
��������ׯ�ĺ��ţ�����������԰�ϲ࣬����һ��ľ�Ƶ�С�š�
�߳�����Ӧ��ͨ����ɽ��С����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "north" :__DIR__"paroad1",

]));

	setup();
	replace_program(ROOM);
}
