inherit NPC;
#include <ansi.h>
 
void create()
{
        set_name("���顸��ڤ��",  ({ "statue" }) );
        set("title", "����");
        set("gender", "Ů��" );
        set("age", 700);
        set("long", @TEXT
���顸��ڤ������ʿ���ڵĻ��������ɵ�ʮ��������֮һ��
����ׯ�Ŀ�ɽ�ȱ�����˵��������������Ϊ
����ׯ��������λ��
TEXT
);
        set("combat_exp", 50000000);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("tenderzhi", 100);
        set_skill("iceforce", 100);
        set_skill("stormdance", 100);
        set_skill("force",100);
        map_skill("force","iceforce");
        map_skill("dodge","stormdance");
        map_skill("unarmed","tenderzhi");
        set("force", 7000);
        set("max_force", 7000);
        set("force_factor", 30);
        set("attitude", "friendly");
         set_temp("apply/armor", 100);

//	carry_object("/obj/weapon/whip")->wield();        
        setup();
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
void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
     if ((string)ob->query("class") != "dancer" ) {
          say( HIY "����һ�����صĸо����ݷ������ڶ����㿴��\n" NOR);
          ob->receive_damage("sen", 20);
          return;
    }
    return;
}

