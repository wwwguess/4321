// Room: /d/canyon/fantasy1.c

inherit ROOM;

void create()
{
	set("short", "�λ��Ծ�ͨ��");
	set("long", @LONG
�������ڣ�ǰ���������ͨ��������ͨ�������䲻ͬ�����մ���
���е���Ũ�����֮��Ϣ���ϵ�����֮ζ��ֹ���µ�Żζ��ͣ������
���Ͽգ���ͣ����֮�õأ���������˿���룬����Ҳ���������ѣ���
ͣ�䶯�ľ��󣬿������!!����֮�л�������Ϊ֮һ�𣬿첽̤���
һ����Ŀռ䡣
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"up" : __DIR__"dream/tmp",
		"down" : __DIR__"evil/tmp",
		"back" : __DIR__"stone_forest3",
		"center" : __DIR__"bamboo/bamboo1",
]));

	setup();
	replace_program(ROOM);
}
