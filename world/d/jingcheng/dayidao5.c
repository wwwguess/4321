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
 "southup" :__DIR__"dayidao4",
  "northdown" :__DIR__"dayidao6",
	]));

	set("outdoors", "heimuya");
	setup();
	replace_program(ROOM);
}

