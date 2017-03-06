
inherit NPC;
inherit F_MASTER;
void re_rank(object);
void create()
{
        set_name("������", ({ "master tie", "master","tie" }) );
        set("gender", "����" );
        set("age", 22);
        set("int", 30);
        set("per", 15);
        set("apprentice_available", 50);
        create_family("��Ѫ������", 8, "����");
        set("long",
                "����������Ѫ�����ŵĴ��ˡ�\n"

                );
        set("force_factor", 100);
        set("max_gin", 350);
        set("max_kee", 600);
        set("max_sen", 350);
        set("eff_gin", 350);
        set("eff_kee", 600);
        set("eff_sen", 350);
        set("gin", 350);
        set("kee", 600);
        set("sen", 350);
        set("max_atman", 300);
        set("atman", 300);
        set("max_force", 2000);
        set("force", 4000);
        set("max_mana", 300);
        set("mana", 300);
        set("attitude", "peaceful");
          set("combat_exp", 2000000);
        set("score", 3000);
        set_skill("dormancy",200);
        set_skill("cuff", 150);
        set_skill("sword", 200);
        set_skill("force", 200);
        set_skill("parry", 120);
        set_skill("literate", 150);
        set_skill("dodge", 200);
        set_skill("ill-quan", 200);
          set_skill("fy-sword", 200);
        set_skill("cloudsforce", 200);
        set_skill("tie-steps", 200);

        prepare_skill("cuff", "ill-quan");
        map_skill("cuff", "ill-quan");
        map_skill("sword", "fy-sword");
        map_skill("force", "cloudsforce");
        map_skill("parry", "fy-sword");
        map_skill("dodge", "tie-steps");

	set("shen_type",1);
                setup();
        carry_object(__DIR__"obj/tieflag");
                carry_object("obj/cloth")->wear();
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 30);
}
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say �����Ž����Ѿ����˶�ʮ�����ӣ���������ͽ�ˡ�");
        }
}
void do_recruit(object ob)
{
        if (ob->query_temp("mark/can_apprentice_master_tie"))
        if( (string)ob->query("gender") != "����" )
          {      command("say ��ֻ���е��ӣ�");
          }
        else {

                command("smile");
                command("say ���պ���д�ɣ�");
                command("smile");
                command("recruit " + ob->query("id") );
         }
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "tieflag");
        re_rank(ob);
        add("apprentice_availavble", -1);
}

void init()
{
   ::init();
   add_action("give_quest", "quest");

}
int accept_object(object me, object obj)
{
        if(obj->query("id")=="silk book" && me->query_temp("mark/silkbook"))
        {
                me->set_temp("mark/can_apprentice_master_tie",1);
                me->delete_temp("mark/silkbook");
                command("say ��⣬�����������\n");
                return 1;
        }
        return 0;
}

void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 3200 ) {
                student->set("title","��Ѫ�����ŵ���");
                return ;
        } else if ( exp <= 12800 ) {
                student->set("title","��Ѫ������С��");
                return ;
        } else if ( exp <= 51200 ) {
                student->set("title","��Ѫ����������");
                return ;
        } else if ( exp <= 153600 ) {
                student->set("title","��Ѫ�����Ŵ���");
                return ;
        } else if ( exp <= 345600 ) {
                student->set("title","��Ѫ����������");
                return ;
        } else if ( exp <= 518700 ) {
                student->set("title","��Ѫ������Ԫ��");
                return ;
        } else if ( exp <= 8624400 ) {
                student->set("title","��Ѫ�����ų���");
                return ;
        } else
                student->set("title","��Ѫ�����Ÿ�����");
                return ;
}

// check if bribe is valid
int valid_bribe(object who,int val) {
        message_vision( (this_object())->query("name")+"��$Nһ˦���䣬˵���� ʲô�������¸���𣿣�\n",who);
        return(0);
}

// called when not finish the task
int quest_punish(object who) {
        message_vision( (this_object())->query("name")+"��$Nһ˦���䣬˵���� �汿����ú�ѧѧ������Ҫ����ɣ�\n" ,who);
    who->set("quest",0);
    return(0);
}


