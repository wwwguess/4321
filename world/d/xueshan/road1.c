//by dwolf
//97.11.8

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"ѩɽС��"NOR);
	set("long",  @LONG
	  �����ھ��׵�ѩɽС���ϣ��е�һ���������ġ����̲�ס������Ц����
���������������������������������΢��ѩ������������������Զ����һЩ����
����ɽ���ߡ����ٺ����Ǹߴ��ɽ�塣
LONG
	);
	set("exits", ([
		"down" : __DIR__"foot.c",
		"northup" : __DIR__"road2.c",
]));
	setup();
}
