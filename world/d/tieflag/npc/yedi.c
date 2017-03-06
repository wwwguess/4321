// zhuzao.c
#include <ansi.h>
inherit NPC;

void create()
{
    set_name("ҹ��",({"ye di","ye","di"}));
    set("long","���ݹ�������뷢�������������ᣬ\n������������Ʈ�ݣ��ִ���һ�ֲ��ɿ���֮���ϡ�\n");
    set("title","");
    set("gender","����");
    set("no_arrest",1);
    set("age",47);
    set("int",22);
    set("cor",30);
    set("per",30);
    set("cps",20);
    set("gin",3000);
    set("max_gin",300);
    set("eff_gin",300);
    set("max_kee",1000);
    set("eff_kee",1000);
    set("kee",1000);  
    set("max_sen",300);
    set("sen",300);    
    set("eff_sen",300);
    set("combat_exp",1500000);  
    set_skill("ill-quan",150);
    set_skill("force",200);
    set_skill("jiayiforce",150);
    set_skill("cuff",200);
    set_skill("parry",150);
    set_skill("dodge",150);
    set("force",3000);
    set("max_force",3000);
    set("force_factor",100);
    map_skill("force","jiayiforce");
    prepare_skill("cuff","ill-quan");
    map_skill("cuff","ill-quan");
    set("attitude", "heroism");
    set("chat_chance",10);     
    set("chat_msg",({
          "ҹ�ۿ�����Ц��\n",
          }) );

    setup();
    carry_object(__DIR__"obj/sicloth")->wear();   
    add_money("tenthousand-cash", 1);
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

int greeting(object me)
{
 
    if( !me || environment(me) != environment() ) return 1;
    if (me->query_temp("marks/pass_hole_to_yedi") && !query_temp("marks/gived_reward") )
    {
    	me->delete_temp("marks/pass_hole_to_yedi"); 
    	set_temp("marks/gived_reward",1);
    	command("say �㾹���߹��ҵ��Թ������˲���");
    	me->add("combat_exp",random(100));
    	me->add("potential",50+random(100));
    }	
    say ("ҹ��˵�������㿴���Ϸ���ط������𣿡�\n");
    return 1;
}
