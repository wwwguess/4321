// by dwolf
//97.11.8
      
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"����ȵ�"NOR);
	set("long", @LONG
	  ����羰����������ʢ���������Ļ��䣬һЩ�۷������ȥ���������
ȫ���ͱڣ����۶�ߵ��Ṧ��û�а취����ȥ��Զ����һ����Ůһ��Ư����Ů����
Ҳ���������ܽ��������⡣
LONG
	);
	set("objects", ([
		__DIR__"npc/xlnu" : 1,
]));
	setup();
}
