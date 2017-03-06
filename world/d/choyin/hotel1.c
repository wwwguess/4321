// Room: /d/choyin/hotel1.c

inherit ROOM;

void create()
{
	set("short", "���־�¥");
	set("long", @LONG
������������س���Զ���ĸ��־�¥���������������ֵ�һ�����
���Դ����������־�¥��һ�ҽ������ϵ꣬�������ڵ���λ�ƹ��Ѿ���
��������������ǳ����˵ص�����ˣ������������ʽ��飬��¥һ¥��
�����س�������ˣ���������һ������ͨ��¥����������������Գ���
�֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"up" : __DIR__"hotel2",
		"west" : __DIR__"s_street2",
	]));
	set("objects", ([
		__DIR__"npc/boss" : 1,
		__DIR__"npc/sergeant" : 1,
	]) );

	setup();
	replace_program(ROOM);
}
