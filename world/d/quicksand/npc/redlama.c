inherit NPC;

void create()
{
        set_name("����", ({ "chi song", "song" }) );
        set("title", "��������");
        set("gender", "����" );
        set("age", 52);
        set("skill_public",1);
        set("int", 30);
        create_family("����", 21, "����");
        set("long",
                "���ɱ��Ǹ��׸�ɮ�ĵ������ӣ����Ǳ����ݺ���������Ϊ��͵\n"
                "�������ӣ��������ʦ�ţ����ڴ˹ȣ���������˫�㣬����˵��\n"
                "�����ӵ����䡣��˵�������ӵ����䣬�����ɻز���������\n"
                );
       set("chat_chance", 5);
        set("chat_msg", ({
                "����˵����˭�����һ������ӣ��ҽ�ȫ���򴫸�����\n",
        }) );

        set("inquiry", ([
                "������": "��....������һ������ʦ�����ɵ��ߵġ�\n",
                "����": "�����ڲ��������ǵĴ������",
        ]) );
        set("attitude", "peaceful");
        set_skill("iron-cloth", 100);
        set_skill("jin-gang", 100);
        set_skill("unarmed", 70);
        set_skill("bloodystrike", 60);
        set_skill("force", 80);
        set_skill("bolomiduo", 75);
        map_skill("unarmed", "bloodystrike");
        map_skill("force", "bolomiduo");
        map_skill("iron-cloth", "jin-gang");
        set("combat_exp", 900000);
        setup();
}
int recognize_apprentice(object ob)
{
        if( !ob->query("marks/song") ){
                say("����˵������ֻ�а����һ������ӣ��ҲŻ����....\n");
                return 0;
        }

        return 1;
}

int accept_object(object who, object ob)
{
        int bonus;
        if( ob->name() != "������")
        {
                       say("����˵����������Ҫ����������....\n");
                        return 1;
        }
        if (ob->query("nature")!= "real" )
        {
                       say("����˵����������Ҳ������ƭ�ˣ����������Ǽٵ�....\n");
                        return 1;
        }
        else
        {
                who->set("marks/song", 1);
                say("����˵�����ã��ã��ã�̫���ˣ��ҵ�ԩ���ڼ�������....\n");
                bonus = (int) who->query("combat_exp");
        bonus += random(100);
        who->set("combat_exp", bonus);
        bonus = (int) who->query("potential") - (int) who->query("learned_points");
        bonus += random(2)+5;
        bonus = (bonus>100? 100:bonus);
        who->set("potential", bonus + (int) who->query("learned_points"));
                
                        return 1;       
        }
                return 1;
}
