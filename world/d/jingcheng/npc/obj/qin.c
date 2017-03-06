// qin.c
// Made by ysgl (1997.10.23)


#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("��β��", ({ "jiaowei qin", "qin", "��β��"}) );
        set_weight(8000);
        set_max_encumbrance(8000);
        set("no_get", 1);
	set("no_drop", 1);
        set("no_shown", 1);
	set("skill", ([
                "name":                 "music",
                "exp_required": 	5000,                
                "sen_cost":             40,     
                "difficulty":   50,            
                "max_skill":    50,           
        ]) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("prep", "on");
                set("unit", "��");
                set("long", "һ�Ž�β�٣�������˾��¡�\n");
                set("value", 100);
                set("material", "wood");
        }
}             

void init()
{
	 if(this_player()==environment())
		add_action("do_play","play");
}
                                   
int do_play(string arg)
{
	object me, obj;
	me = this_player();

	if( !arg || (arg != "��β��" && arg != "��" && arg != "qin") )
		return notify_fail("���뵯ʲô��\n");
	if( !(obj = present("jiaowei qin", me)) )
		return notify_fail("û���٣��㵯ʲô����\n");
	if( me->query_skill("music", 1) > 30 ){
		tell_object(me,
	GRN"�㵯��һ����ɽ��ˮ�������������������ӿ���ֱк���£������������\n"NOR);		
		return 1;
	}
        tell_object(me,
	GRN"�㵯��һ��������ˣ����������㼼�ղ�����������ɬ��ʹ���ڶ���Ƨ��\n"NOR);
	return 1;
}

int is_container() { return 1; }

void owner_is_killed() 
{ 
        remove_call_out("dest");
        call_out("dest", 1, this_object());
}

void dest(object ob)
{
	destruct(ob);
}
