#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"Ԭ���"NOR);
	set("long", @LONG
������ǵ��������̨������Ԭ��ļҡ����￴���������Ǻ���
����Ԭ��������ڳ������£������Ǽ��ղŻؼ�һ�Σ�����������
��ġ�
LONG         
	);

	set("exits", ([ 
 "east"  :__DIR__"ql5",
 	]));
	setup();
	
}

