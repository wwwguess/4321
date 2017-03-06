// Room: /d/choyin/court1.c

inherit ROOM;

void create()
{
	set("short", "�ظ�����");
	set("long", @LONG
�����������ظ����ŵĴ��ţ�������ӡ���е�����һ�㣬�ߴ�Ĵ�
�š���ֻ�޴��ʯʨ���Լ�һ������Ϊ֮��Ȼ�����ա��ſ���һ���Ƥ
��(drum)������˵���⵱Ȼ���ð��ջ�����ԩ�õģ������ص�֪�ؾ�˵
�ǻ�������ֶ�ӣ���Ȼ�㲻���ǰ����죬������Ҳû����˵����ʲô̰
���������Ӽ���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"north" : __DIR__"yamen_yard",
		"south" : __DIR__"crossroad",
	]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");
	set("objects", ([
		__DIR__"npc/judge_gu.c" : 4,
                __DIR__"npc/magistra.c" : 2
	]) );

	setup();
	replace_program(ROOM);
}
