//thief.c
inherit NPC;

void create()
{
        set_name("����", ({ "thief" }) );
        set("rank", "����");
        set("gender", "����" );
        set("age", 35);
        set("int", 25);
        set("con", 28);
        set("long", @LONG
    ����������û�ڴ��˼�, ��Ϊ���Ṧ��ǿ, �ٸ�Ҳ����û�а취��
LONG
);
        set("combat_exp", 3000);
        set("attitude", "heroism");
        set("env/wimpy", 70);

        set("chat_chance", 40);
        set("chat_msg", ({
                "����˵��: С���Ұ�������⵰! �ŵ��㲻����Ǯ߬����\n",
               (: random_move :)
        }) );

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                "������ݺݵ�˵��: �������û����£�",
                "�����ȵ�: ��Ҫ�Ǹ�����, �����Ժ��û��!"
        }) );

        set_skill("dodge", 140);
        set_skill("parry", 100);
        set_skill("unarmed", 30);
        set_skill("move", 100);
        set_skill("stealing", 70);

        setup();

        add_money("gold", 3);
        carry_object("/u/cloud/obj/cloth/black_cloth")->wear();
        set("score",-30);
}

init()
{
        //int steal_flag;
        object ob;

        ::init();

        if( interactive(ob = this_player()) && !is_fighting() ) {
                if (random((int)ob->query("kar")) < 2) {   // ͵�ĸ���
                        remove_call_out("steal_it");
                        call_out("steal_it", 1, ob);
                }
        } else {        // ����ս��״̬���͵
                remove_call_out("steal_it");
                call_out("steal_it", 1, ob);
        }

}

void steal_it(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        command("grin");
        command("steal silver from " + ob->query("id"));

}

int accept_fight(object me)
{
        command("say ��С��, ��Ȼ�����ү������, ����!");
        command("grin");
        kill_ob(me);
        return 1;
}

