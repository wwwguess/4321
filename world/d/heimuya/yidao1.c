// Room: /d/heimuya/.c
// write by: dfbb 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","���");
	set("long", @LONG
    ����ͨ�� "������"��������������������������ӵ�
���̣����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡�
��ʱ����������������߷ɳ۶���������һ·��������·����
����������������֡�

LONG
	);

	set("exits", ([
		"southwest" :"/d/road/rdktojd3",
		"northeast" :__DIR__"sancha",

	]));

	set("outdoors", "heimuya");
	setup();
	replace_program(ROOM);
}

