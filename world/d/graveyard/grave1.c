// Room: /d/graveyard/grave1.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
��������վ��һ������ڵĲݴ��������ȥ���涼��һ�طص���
�ѣ����������Ķ���һЩ�������磬�������޹ʵĿ����ˣ������ĵ�
���������������Ϊ���귦������������Ӳ��ܲ���������������
�ϵ����������׳ơ�����졹��С�컨��Ҳ��������������ʬ�ǵ�����
������ĺ컨�����ִ��ֹ��졣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"southeast" : __DIR__"road1",
]));
	set("outdoors", "graveyard");

	setup();
	replace_program(ROOM);
}
