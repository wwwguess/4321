// magic_seal.c

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit F_CLEAN_UP;


inherit ITEM;

void create()
{
	set_name("����", ({"seal"}) );
	set_weight(5);
	set("long",
		"����һ�Ż��õķ��䣬�� burn ��������ĳ��(��ĳ��)���ϡ�\n");
	set("unit", "��");
}

int unequip()
{
	set("equipped", 0);
	return 1;
}
void init()
{
add_action("do_warp", "burn");
}


int do_warp(string tar)
{       
        object env,who;
       
       
        who=this_player();
    //  if( who && who!=this_player() )
          //  return notify_fail("���紫�ͷ�ֻ�ܶ��Լ�ʹ�á�\n");

    //  env = environment(this_player());
      message("vision",
              HIB + this_player()->name() + "����һ�����紫�ͷ���\n\n"
                
   "��Ȼ���ܴ�����һ�����쬵����磬����֮���ݷ��������Ӱ�ڻζ�...\n\n"
                "Ȼ��һ����ͻȻ����\n" NOR, env);
        //OP_CMD->main(this_player(), "all");
     
           who->move(DEATH_ROOM);
        message("vision",
                CYN "����...." + who->name() + "�Ѿ������ˡ�\n" 
NOR, env);
        message("vision",
                CYN 
"��ֻ�������Ӳ�����׹��һֱ��׹��һֱ��׹��һֱ��׹��һֱ��׹ .....\n\n"
                NOR     
"��֪��ʲ��ʱ���㷢������ʵһֱ��վ�ڼ�Ӳ�ĵ����ϣ��������ܵľ���\n\n"
                        "ȴ��һ����....\n", this_player() );
        destruct(this_object());
        return 1;
}

/*
void init()
{
	add_action("do_attach", "burn");
}

int do_attach(string arg)
{
	string sheet, dest;
	object ob;
	function f;

	if( !arg || sscanf(arg, "%s to %s", sheet, dest)!=2 )
		return notify_fail("ָ���ʽ��attach <����> to <Ŀ��>\n");
	
	if( !id(sheet) ) return 0;

	ob = present(dest, this_player());
	if( !ob ) ob = present(dest, environment(this_player()));
	if( !ob ) return notify_fail("��Ҫ��ʲ�ᶫ��ʹ�����ŷ��䣿\n");

	if( !functionp(f = query("attach_func", 1)) )
		return notify_fail("���ŷ�û���á�\n");

	if( evaluate(f, ob) ) {
		if( ob!=this_player() )
			message_vision("$N�ó�һ��" + name() + "��$nһ����\n", this_player(), ob);
		if( ob && ob->is_character() ) {
			move(ob);
			set("equipped", "sealed");
			set("no_drop", "�����������ܶ����������� detach��\n");
		} else destruct(this_object());
		return 1;
	} else 
		return 0;
}
*/