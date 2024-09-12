/*
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
package org.apache.airavata.helix.adaptor;

import org.apache.airavata.agents.api.AgentException;
import org.apache.airavata.agents.api.AgentUtils;
import org.apache.airavata.agents.api.CommandOutput;
import org.apache.airavata.model.appcatalog.computeresource.ComputeResourceDescription;
import org.apache.airavata.model.credential.store.SSHCredential;
import org.apache.airavata.model.data.movement.DataMovementProtocol;
import org.apache.airavata.model.data.movement.SCPDataMovement;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.util.Optional;

public class SSHJComputeStorageAdaptor extends SSHJAgentAdaptor {

    private final static Logger logger = LoggerFactory.getLogger(SSHJComputeStorageAdaptor.class);

    @Override
    public void init(String computeResource, String gatewayId, String userId, String token) throws AgentException {
        try {
            logger.info("Initializing Compute Resource SSH Adaptor for compute resource: {}, gateway: {}, user: {}, token: {}", computeResource, gatewayId, userId, token);

            ComputeResourceDescription computeResourceDescription = AgentUtils.getRegistryServiceClient().getComputeResource(computeResource);

            logger.info("Fetching data movement interfaces for compute resource {}", computeResource);

            var dataMovementInterface = computeResourceDescription.getDataMovementInterfaces()
                    .stream()
                    .filter(iface -> iface.getDataMovementProtocol() == DataMovementProtocol.SCP)
                    .findFirst()
                    .orElseThrow(() -> new AgentException("No SCP DataMovementInterface found for compute resource " + computeResource));

            SCPDataMovement scpDataMovement = AgentUtils.getRegistryServiceClient().getSCPDataMovement(dataMovementInterface.getDataMovementInterfaceId());

            logger.info("Fetching credentials for credential store token {}", token);

            SSHCredential sshCredential = AgentUtils.getCredentialClient().getSSHCredential(token, gatewayId);

            if (sshCredential == null) {
                throw new AgentException("Null credential for token " + token);
            }
            logger.info("Description for token {}: {}", token, sshCredential.getDescription());

            String selectedHostName = Optional.ofNullable(scpDataMovement.getAlternativeSCPHostName())
                    .filter(host -> !host.isBlank())
                    .orElseGet(computeResourceDescription::getHostName);

            int selectedPort = scpDataMovement.getSshPort() == 0 ? 22 : scpDataMovement.getSshPort();

            logger.info("Using user {}, Host {}, Port {} to create SSH client for compute resource storage {}",
                    userId, selectedHostName, selectedPort, computeResource);

            createPoolingSSHJClient(userId, selectedHostName, selectedPort,
                    sshCredential.getPublicKey(), sshCredential.getPrivateKey(), sshCredential.getPassphrase());

        } catch (Exception e) {
            logger.error("Error while initializing SSH agent for compute resource storage {} with token {}", computeResource, token, e);
            throw new AgentException("Error while initializing ssh agent for compute resource storage " + computeResource + " to token " + token, e);
        }
    }


    @Override
    public void uploadFile(String localFile, String remoteFile) throws AgentException {
        super.uploadFile(localFile, remoteFile);
    }

    @Override
    public void downloadFile(String remoteFile, String localFile) throws AgentException {
        super.downloadFile(remoteFile, localFile);
    }

    @Override
    public CommandOutput executeCommand(String command, String workingDirectory) throws AgentException {
        return super.executeCommand(command, workingDirectory);
    }
}
