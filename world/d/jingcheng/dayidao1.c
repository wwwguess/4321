// Room: /d/heimuya/.c
// write by: dfbb 
// date 97/01/25

inherit ROOM;

void create()
{
      set("short","�����");
	set("long", @LONG
����һ��������ֱ�����������ݵ���ʮ���ۡ�����ͨ��
������������ֱ�ﾩ�ǡ�����ͨ�����Ǳؾ�֮·���������
���Ÿ���ͦ�ε�������·�����������������������ھ�����
����֮��.
LONG
	);

	set("exits", ([
   "southwest" : "/d/heimuya/bdcm",
 "northeast" :__DIR__"dayidao2",
	]));

	set("outdoors", "heimuya");
	setup();
	replace_program(ROOM);
}

