#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"��լ"NOR);
	set("long", @LONG
�⻧��լ�ӽṹ�Ͽ������൱����ģ���ʾ���⻧�˼���ǰ�ƺ���
����������֪����һ����ҵ���ʼ˥���ˣ���������Ҳ��֮���ʧ
�ޡ������⻧�˼ҵ��������Ӹ������������ֺ��У�������ҵ��
LONG         
	);

	set("objects", ([ 
        __DIR__"npc/baijia" : 3,
      ]));

	set("exits", ([ 
	 "west" :__DIR__"ql1",
 	]));

	setup();
	
}

