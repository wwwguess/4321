// seal.c write by sb 97.11.14

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
      message_vision( HIB"$N����һ�����紫�ͷ���\n\n",who);             
   message_vision("��Ȼ���ܴ�����һ�����쬵����磬����֮���ݷ��������Ӱ�ڻζ�...\n\n",who);
                message_vision("Ȼ��һ����ͻȻ����\n" NOR,who);
        //OP_CMD->main(this_player(), "all");
     
                   message_vision(
                CYN "����....$N�Ѿ������ˡ�\n"NOR,who);
        message("vision",
                CYN 
"��ֻ�������Ӳ�����׹��һֱ��׹��һֱ��׹��һֱ��׹��һֱ��׹ .....\n\n"
                NOR     
"��֪��ʲ��ʱ���㷢������ʵһֱ��վ�ڼ�Ӳ�ĵ����ϣ��������ܵľ���\n\n"
                        "ȴ��һ����....\n", this_player() );
      who->move(DEATH_ROOM);

        destruct(this_object());
        return 1;
}
