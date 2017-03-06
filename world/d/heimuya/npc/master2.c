
inherit NPC;
inherit F_MASTER;

void create()
{
                object armor;
        set_name("�պ�", ({ "master queen", "master","queen" }) );
        set("gender", "Ů��" );
        set("age", 46);
        set("int", 30);
        set("per", 30);
        set("apprentice_available", 50);
        create_family("������", 7, "����");
        set("long",
                "�պ�����Ѫ�����ŵ��ߴ�����������֮�ޣ��򿴲�����Ѫ�������˶���\
n"
                "���ӵ����飬����������һ�ɣ�������������������Ů�ӡ�\n"
                );
        set("force_factor", 30);
        set("max_gin", 200);
        set("max_kee", 500);
        set("max_sen", 300);
        set("eff_gin", 200);
        set("eff_kee", 500);
        set("eff_sen", 300);
        set("gin", 200);
        set("kee", 500);
        set("sen", 300);
        set("max_atman", 200);
        set("atman", 200);
        set("max_force", 1000);
        set("force", 1000);
        set("max_mana", 300);
        set("mana", 300);
        set("attitude", "peaceful");
          set("combat_exp", 2000000);
        set("score", 1000);
        set_skill("dormancy",100);
        set_skill("cuff", 80);
        set_skill("sword", 100);
        set_skill("force", 100);
        set_skill("parry", 80);
        set_skill("literate", 120);
        set_skill("dodge", 100);
        set_skill("ill-quan", 80);
        set_skill("fy-sword", 100);
        set_skill("jiayiforce", 80);
        set_skill("tie-steps", 130);

        map_skill("cuff", "ill-quan");
        map_skill("cuff", "ill-quan");
        map_skill("sword", "fy-sword");
        map_skill("force", "jiayiforce");
        map_skill("parry", "fy-sword");
        map_skill("dodge", "tie-steps");

                setup();
            armor=new(__DIR__"obj/corclot");
                armor->set_name("����˿��",({"cloth"}) );
                armor->move(this_object());
                armor->wear();

}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
}
void attempt_apprentice(object ob)
{
	object student;
	int exp;
	student=ob;
	exp=(int) ob->query("combat_exp");
        if((int) ob->query("combat_exp")<100000) return;
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say �����Ž����Ѿ����˶�ʮ�����ӣ���������ͽ�ˡ�");
        }
        if( exp <= 3200 ) {
                student->set("title","����������");
                return ;
        } else if ( exp <= 12800 ) {
                student->set("title","������С��Ů");
                return ;
        } else if ( exp <= 51200 ) {
                student->set("title","��������Ů");
                return ;
        } else if ( exp <= 153600 ) {
                student->set("title","����������Ů");
                return ;
        } else if ( exp <= 345600 ) {
                student->set("title","��������Ů");
                return ;
        } else if ( exp <= 518700 ) {
                student->set("title","��������Ů");
                return ;
        } else if ( exp <= 8624400 ) {
                student->set("title","������ʥŮ");
                return ;
        } else
                student->set("title","������������");
}
void do_recruit(object ob)
{
        if( (string)ob->query("gender") != "Ů��" )
          {      command("say ��ֻ��Ů���ӣ�");
          }
        else {

                command("smile");
                command("say ���պ���д�ɣ�");
                command("smile");
                command("recruit " + ob->query("id") );
		ob->delete("betrayer");
        }
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "tieflag");
        add("apprentice_availavble", -1);
}

void init()
{
   add_action("give_quest", "quest");

}


int valid_bribe(object who,int val) {
        message_vision( (this_object())->query("name")+"��$Nһҡͷ��˵���� ����-
Ǯ��ʲô����\n",who);
        return(0);
}

// called when not finish the task
int quest_punish(object who) {
        message_vision( (this_object())->query("name")+"��$N̾�˿�����˵���� ��-
�ú�ѧѧ������Ҫ����ɣ�\n" ,who);
    who->set("quest",0);
    return(0);
}


