// Room: /d/heimuya/.c
// write by: dfbb 
// date 97/01/25

#include <localtime.h>
inherit ROOM;
int flag=0;

void create()
{
	set("short","���");
	set("long", @LONG
    ����ͨ�� "������"���������������������
���߾Ϳ쵽��������,������һ�����ֺŵĿ�ջ
"˳����ջ".	
LONG
	);

	set("exits", ([
		"south" :__DIR__"yidao4",
		"north" :__DIR__"sancha",
                "west"  :__DIR__"kezhan",
	]));

	set("outdoors", "heimuya");
	setup();
}

