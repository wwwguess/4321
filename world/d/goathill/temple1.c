// Room: /d/goathill/temple1.c

inherit ROOM;

void create()
{
	set("short", "С������");
	set("long", @LONG
��������վ��һ��С�������У���������ϱ����涼��������ɽ��
�����ģ�ֻ�ж���һ����ǽ��ǽ��Ƕ��һ��СС����������湩��һ��
���Ʋ���������үү��������������ߡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"mroad3",
	]));
	set("objects", ([
		__DIR__"npc/bandit_hwang" : 1,
	]) );

	setup();
	replace_program(ROOM);
}
