//ROOM:/d/suzhou/wmci.c
//by dwolf
//97.11.7 
         
#include <ansi.h>
inherit ROOM;            

void create()
{                           
	set("short", RED"������"NOR);
	set("long", @LONG
        	 �������¹����ɵ����ã����ɱ��������������������ں�����
���ߣ�������ȴ�������ݡ�˭Ҳ��֪��Ϊʲô������������������ŮŮ����������λ
����Ӣ�ۡ���Ҳ��Ҳ�ø�����ͷ(ketou)��
LONG
	);                                        
	set("exits", ([
		"west" : __DIR__"nroad1", 
]));             
	set("objects", ([
		__DIR__"npc/girl.c" : 1,    
		__DIR__"npc/woman.c" : 1,
]));
	setup();
}              

void init()
{
	add_action("do_ketou", "ketou");
}

int do_ketou()(string arg)
{
	object me;
	me = this_player(); 
	                  
	if (me->query("combat_exp") >= 500000) {
		message_vision("�����ͷ��ͻȻ���¿���һ����������˽�ȥ��");
		me->move("/d/suzhou/mishi");  
	}
  
	if ( me->query("chao_ting") <= 1000) {
	me->add("chao_ting", 1);
	me->add("gin", -1);
	message_vision("�㹧�������ع��£�������Ԫ˧�������ͷ����ĳ�͢�ҳ϶������ˡ�\n");
	}
	else {
		return	"�������Ԫ˧�����񹧹������Ŀ���һ��ͷ��";
	}                   

	if (me->query("combat_exp") >= 500000) {
	me->move("/d/suzhou/mishi");
}
	
  

