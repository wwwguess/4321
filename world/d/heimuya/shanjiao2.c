// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","��С��");
	set("long", @LONG
������������һ����᫵�ɽ·�ϣ�����͹͹��ɽʯ�̵���Ľŵ���
�����ۣ����߸����߶��Ƕ��͵�ɽ�ڣ�ɽ·����ͨ����������Ⱥɽ֮��
LONG
	);

	set("exits", ([
		"northup" :__DIR__"shanjiao3",
                "southdown" :__DIR__"shanjiao1",
	]));

	set("outdoors", "heimuya");
	setup();
	replace_program(ROOM);
}

