inherit NPC;
#include <ansi.h>
 
void create()
{
         set_name("���", ({ "phoenix","fire" }) );
        set("title", "��ׯ����");
        set("nick","����");
        set("gender", "Ů��" );
        set("age", 27);
        set("long", @TEXT
���񡸷�ˡ�����ʿ���ڵĻ��������ɵ�ʮ��������֮һ��
�����������񼣣�������ׯ����Ϊ��ׯ���ޡ�
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
     if ((string)ob->query("gender") == "����" ) {
          say( HIY "����������䣬�û����߲ʷ�ˣ����ֽ�ɫ��â��\n" NOR);
          kill_ob(ob);
          ob->fight_ob(this_object());
          return;
    }
}

