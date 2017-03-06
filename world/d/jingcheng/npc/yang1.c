//created by ysg,add by kiss
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 
inherit F_VENDOR;

void create()
{
	set_name("����˳", ({ "yang zhongshun" , "yang" , "zhongshun" }));
	set("title","ҩ���ƹ�");
	set("nickname", CYN"������ҽ"NOR); 
	set("long",
	"���ϰ��ǳ��������洫����ҽ����Ȼ���ᣬȴ�����������⡣�������и���Ƨ�����ǲ����˵�ʱ��\n"
	"�����������ӡ����ǵ����������Ҳ�޼����£������ǲ�Ը��ܡ����Բŵ��ˡ�������ҽ����ôһ����ͷ��\n");
	set("gender", "����");
	set("age", 35);
   set("vendor_goods",([
         __DIR__"obj/jinchuang":20,
        __DIR__"obj/gao":20,
   ]));
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("per", 30);
	set("force", 50);
	set("max_force", 50);
	set("force_factor", 2);
	set("combat_exp", random(100000));
	set_skill("dodge", 30);
	set_skill("unarmed", 40);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 5);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"����˳����ĳ�����һ�ۣ�Ť��ͷȥ������������Զ�������ҽ�顣\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
}
void init()
{
	object me;
    	::init();
        add_action("do_vendor_list","list");
    	if( interactive(me = this_player()) && !is_fighting() ) 
	{
        	remove_call_out("greeting");
        	call_out("greeting", 3, me);
        	return;
        }
}
string greeting(object me)
{
	int my_max_qi;
	
	my_max_qi = me->query("max_kee");

	if( ((int)me->query("kee")*100/my_max_qi) > 95 )
		return RANK_D->query_respect(me)+"��������Ѫ��ӯ����֪��С�����кι�ɣ�\n";

	if( ((int)me->query("kee")*100/my_max_qi) > 75 )
		return RANK_D->query_respect(me)+"Щ��С�ˣ�������������ҩ������ҩ��������\n";

	if( ((int)me->query("kee")*100/my_max_qi) > 55 )
		return RANK_D->query_respect(me)+"�˵ÿɲ��ᰡ�����������������ҩר�θ��ֵ��ˡ����ˣ�����ЧŶ��\n";	

	return RANK_D->query_respect(me)+"���Ƴ��أ��������Ͼ��Σ�����������Σ�յģ�\n";	
}
