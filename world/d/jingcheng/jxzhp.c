#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"�����ӻ���"NOR);
	set("long", @LONG
��֪Ϊʲô�������ȴֻ����һ���ӻ��̡�����ÿ������������
Ҳͦ���֡��������������ν��ף����Ǵ��װ��棬������ȫ����
���ɨ��Ҳʮ�ָɾ���κ�ϰ��ںͼ�λ����˵˵ЦЦ��
LONG         
	); 
	set("objects", ([
		"/d/jingcheng/npc/wei.c" : 1,
]));

	set("exits", ([ 
 "west"  :__DIR__"ql5",
 	]));
	setup();
	
}

