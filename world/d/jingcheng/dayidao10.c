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
����֮��.������Ǿ��ǵ��������ˡ�
LONG
	);

	set("exits", ([
 "southup" :__DIR__"dayidao9",
 "east" :__DIR__"xizhimen",
	]));
       set("objects", ([
 "open/diablo/xingren" : 2,
        ]));

	set("outdoors", "heimuya");
	setup();
	replace_program(ROOM);
}

